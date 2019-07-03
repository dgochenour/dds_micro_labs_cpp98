
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#ifndef rti_me_cpp_hxx
#include "rti_me_cpp.hxx"
#endif

#include "quickstart.h"
#include "quickstartSupport.h"
#include "quickstartPlugin.h"
#include "quickstartApplication.h"

using namespace DDS;

class myTypeReaderListener : public DataReaderListener
{

  public:

    virtual void on_data_available(DataReader *reader);

    // LAB #2 -- add a callback for incompatible QoS
    virtual void on_requested_incompatible_qos(DDSDataReader *reader, const DDS_RequestedIncompatibleQosStatus &status);     
};

template <typename T>
void take_and_print(typename T::DataReader* reader)
{
    ReturnCode_t retcode;
    SampleInfo sample_info;
    T *sample = NULL;

    sample = T::TypeSupport::create_data();
    if (sample == NULL)
    {
        printf("Failed sample initialize\n");
        return;
    }

    retcode = reader->take_next_sample(*sample, sample_info);
    while (retcode == RETCODE_OK)
    {
        if (sample_info.valid_data)
        {
            printf("\nValid sample received\n");
            /* TODO read sample attributes here */

            // LAB #1 -- print out the members of the received sample
            std::cout << "id = " << sample->id << std::endl;
            std::cout << "value1 = " << sample->value1 << std::endl;
            std::cout << "name = " << sample->name << std::endl;
        }
        else
        {
            printf("\nSample received\n\tINVALID DATA\n");
        }
        retcode = reader->take_next_sample(*sample, sample_info);
    }

    T::TypeSupport::delete_data(sample);
}

// LAB #2 -- implement the callback 
void myTypeReaderListener::on_requested_incompatible_qos(
        DDSDataReader *reader, 
        const DDS::RequestedIncompatibleQosStatus &status) {
            
    std::cout << "Incompatible QoS! Count: " << status.total_count << std::endl;
}
void

myTypeReaderListener::on_data_available(DataReader * reader)
{
    myModule::myTypeDataReader *hw_reader = myModule::myTypeDataReader::narrow(reader);
    take_and_print<myModule::myType>(hw_reader);
}

// LAB #7 -- make a copy of the listener callback, just to reuse the code we have
void my_on_data_available(DDSDataReader * reader) {
    myModule::myTypeDataReader *hw_reader = myModule::myTypeDataReader::narrow(reader);
    take_and_print<myModule::myType>(hw_reader);
}
int
subscriber_main_w_args(Long domain_id, char *udp_intf, char *peer,
Long sleep_time, Long count)
{
    Subscriber *subscriber = NULL;
    DataReader *datareader = NULL;
    myTypeReaderListener *listener  = new myTypeReaderListener();
    DataReaderQos dr_qos;
    ReturnCode_t retcode;
    Application *application = NULL;

    // LAB #7 -- add WaitSet-related variables
    DDSWaitSet *waitset = NULL;
    DDSStatusCondition *status_condition = NULL;
    DDS_Duration_t wait_timeout = { 15, 0 };
    int active_conditions = 0;
    DDSConditionSeq active_conditions_seq;

    application = new Application();
    if (application == NULL)
    {
        printf("failed Application new\n");
        goto done;
    }

    retcode = application->initialize("subscriber", 
    "publisher", 
    domain_id,
    udp_intf, 
    peer, 
    sleep_time, 
    count);
    if (retcode != RETCODE_OK)
    {
        printf("failed Application initialize\n");
        goto done;
    }

    subscriber = application->participant->create_subscriber(
        SUBSCRIBER_QOS_DEFAULT,NULL,
        STATUS_MASK_NONE);
    if (subscriber == NULL)
    {
        printf("subscriber == NULL\n");
        goto done;
    }

    retcode = subscriber->get_default_datareader_qos(dr_qos);
    if (retcode != RETCODE_OK)
    {
        printf("failed get_default_datareader_qos\n");
        goto done;
    }

    dr_qos.resource_limits.max_samples = 32;
    dr_qos.resource_limits.max_instances = 1;
    dr_qos.resource_limits.max_samples_per_instance = 32;
    /* if there are more remote writers, you need to increase these limits */
    dr_qos.reader_resource_limits.max_remote_writers = 10;
    dr_qos.reader_resource_limits.max_remote_writers_per_instance = 10;
    dr_qos.history.depth = 32;

    // LAB #7 -- comment out to return to shared ownership
    // LAB #6 -- introduce exculsive ownership
    //dr_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;
    
    // LAB #4 -- set DR & DW  both to 1.5s deadline
    // LAB #2 -- add a deadline to DataReader 
    dr_qos.deadline.period.sec = 1;
    dr_qos.deadline.period.nanosec = 500000000; // .5s

    /* Reliability QoS */
    #ifdef USE_RELIABLE_QOS
    dr_qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
    #else
    dr_qos.reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
    #endif

    // LAB #7 -- remove the DDS_DATA_AVAILABLE_STATUS mask
    // LAB #2 -- add the DDS_REQUESTED_INCOMPATIBLE_QOS_STATUS mask
    datareader = subscriber->create_datareader(
        application->topic,
        dr_qos,
        listener,
        DDS_REQUESTED_INCOMPATIBLE_QOS_STATUS);

    if (datareader == NULL)
    {
        printf("datareader == NULL\n");
        goto done;
    }

    // LAB #7 -- get the DataReader's status_condition     
    status_condition = datareader->get_statuscondition();
    if (!status_condition) {
        std::cout << "Error getting status_condition from datareader" << std::endl;
        goto done;
    }

    // LAB #7 -- set the events / status change in which we are interested
    retcode = status_condition->set_enabled_statuses(DDS_DATA_AVAILABLE_STATUS);
    if (retcode != DDS_RETCODE_OK) {
        std::cout << "Error setting enabled statuses" << std::endl;
        goto done;
    }    

    // LAB #7 -- Initialize the active condition sequence
    if (!active_conditions_seq.maximum(1)) {
        std::cout << "Error setting maximum of active_conditions" << std::endl;
        goto done;
    }

    // LAB #7 -- create the WaitSet
    waitset = new DDSWaitSet();
    if(!waitset) {
        std::cout << "Error allocating WaitSet" << std::endl;
        goto done;
    }

    // LAB #7 -- attach the status condition to the waitset  
    retcode = waitset->attach_condition(status_condition);
    if (retcode != DDS_RETCODE_OK) {
        std::cout << "Error attaching condition to waitset" << std::endl;
        goto done;
    }

    retcode = application->enable();
    if (retcode != RETCODE_OK)
    {
        printf("failed to enable application\n");
        goto done;
    }

    if (application->count != 0)
    {
        printf("Running for %d seconds, press Ctrl-C to exit\n",
        application->count);
        OSAPI_Thread_sleep(application->count * 1000);
    }
    else
    {
        // LAB #7 -- add a loop to simply run the WaitSet code forever (until a ctrl-C, anyway)
        
        // Because we only attached 1 condition to the waitset, we know
        // that it will be either DDS_DATA_AVAILABLE_STATUS or a timeout that causes
        // the waitset to return
         
        // If there were more active conditions, we would need to iterate through
        // active_conditions to see which status changed
        while(1) {
            
            retcode = waitset->wait(active_conditions_seq, wait_timeout);
            if (retcode == DDS_RETCODE_OK) {
                // we got some data
                my_on_data_available(datareader);
            } else if (retcode == DDS_RETCODE_TIMEOUT) {
                // timeout
                std::cout << "wait timed out, no conditions triggered" << std::endl;
                continue;
            } else {
                // error
                std::cout << "Wait error: " << retcode << std::endl;
                break;
            }
        }

    }

    done:

    if (application != NULL)
    {
        delete application;
    }

    if (listener != NULL)
    {
        delete listener;
    }

    //DataReaderQos is automatically disposed by destructor

    return 0;
}

#if !(defined(RTI_VXWORKS) && !defined(__RTP__))
int
main(int argc, char **argv)
{
    Long i = 0;
    Long domain_id = 0;
    char *peer = NULL;
    char *udp_intf = NULL;
    Long sleep_time = 1000;
    Long count = 0;

    for (i = 1; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-domain"))
        {
            ++i;
            if (i == argc)
            {
                printf("-domain <domain_id>\n");
                return -1;
            }
            domain_id = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-udp_intf"))
        {
            ++i;
            if (i == argc)
            {
                printf("-udp_intf <interface>\n");
                return -1;
            }
            udp_intf = argv[i];
        }
        else if (!strcmp(argv[i], "-peer"))
        {
            ++i;
            if (i == argc)
            {
                printf("-peer <address>\n");
                return -1;
            }
            peer = argv[i];
        }
        else if (!strcmp(argv[i], "-sleep"))
        {
            ++i;
            if (i == argc)
            {
                printf("-sleep_time <sleep_time>\n");
                return -1;
            }
            sleep_time = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-count"))
        {
            ++i;
            if (i == argc)
            {
                printf("-count <count>\n");
                return -1;
            }
            count = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-h"))
        {
            Application::help(argv[0]);
            return 0;
        }
        else
        {
            printf("unknown option: %s\n", argv[i]);
            return -1;
        }
    }

    return subscriber_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#elif defined(RTI_VXWORKS)
int
subscriber_main(void)
{
    /* Explicitly configure args below */
    Long domain_id = 44;
    char *peer = "10.10.65.103";
    char *udp_intf = NULL;
    Long sleep_time = 1000;
    Long count = 0;

    return subscriber_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#endif
