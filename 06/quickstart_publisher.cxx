
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#ifndef rti_me_cpp_hxx
#include "rti_me_cpp.hxx"
#endif

#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"

#include "quickstart.h"
#include "quickstartSupport.h"
#include "quickstartApplication.h"

class myModule_myTypeDataWriterListener : public DDSDataWriterListener {

public:

    myModule_myTypeDataWriterListener() : DDSDataWriterListener() { }
    ~myModule_myTypeDataWriterListener() { }

    // LAB #3 -- add a callback for incompatible offered QoS
    virtual void on_offered_incompatible_qos(DDSDataWriter *writer, const DDS_OfferedIncompatibleQosStatus &status);
};

// LAB #3 -- implement the callback 
void myModule_myTypeDataWriterListener::on_offered_incompatible_qos(
        DDSDataWriter *writer, 
        const DDS_OfferedIncompatibleQosStatus &status) {

    std::cout << "Incompatible QoS! Policy ID: " << status.last_policy_id << std::endl;
}

int
publisher_main_w_args(DDS_Long domain_id, char *udp_intf, char *peer,
DDS_Long sleep_time, DDS_Long count)
{
    Application *application = NULL;

    DDSPublisher *publisher = NULL;
    DDSDataWriter *datawriter = NULL;
    myModule_myTypeDataWriter *hw_writer = NULL;
    DDS_DataWriterQos dw_qos;
    DDS_ReturnCode_t retcode;
    myModule_myType *sample = NULL;
    DDS_Long i;
    // LAB #3 -- instantiate a DW listener
    DDSDataWriterListener *dw_listener = new myModule_myTypeDataWriterListener();

    application = new Application();
    if (application == NULL)
    {
        printf("failed Application new\n");
        goto done;
    }

    retcode = application->initialize("publisher", 
    "subscriber", 
    domain_id,
    udp_intf, 
    peer, 
    sleep_time, 
    count);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed Application initialize\n");
        goto done;
    }

    publisher = application->participant->create_publisher(
        DDS_PUBLISHER_QOS_DEFAULT,NULL,DDS_STATUS_MASK_NONE);
    if (publisher == NULL)
    {
        printf("publisher == NULL\n");
        goto done;
    }

    retcode = publisher->get_default_datawriter_qos(dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed get_default_datawriter_qos\n");
        goto done;
    }

    #ifdef USE_RELIABLE_QOS
    dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    #else
    dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    #endif
    dw_qos.resource_limits.max_samples = 32;
    dw_qos.resource_limits.max_samples_per_instance = 32;
    dw_qos.resource_limits.max_instances = 1;
    dw_qos.history.depth = 32;

    // LAB #6 -- introduce exculsive ownership
    dw_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;
    dw_qos.ownership_strength.value = 10;

    // LAB #2 -- Add deadline to the DataWriter Qos
    dw_qos.deadline.period.sec = 1;
    dw_qos.deadline.period.nanosec = 500000000; // .5s

    // LAB #3 -- add the incompatible qos mask and specify the listener
    datawriter = publisher->create_datawriter(
            application->topic,
            dw_qos,
            dw_listener,
            DDS_OFFERED_INCOMPATIBLE_QOS_STATUS);
    if (datawriter == NULL)
    {
        printf("datawriter == NULL\n");
        goto done;
    }

    retcode = application->enable();
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to enable application\n");
        goto done;
    }

    hw_writer = myModule_myTypeDataWriter::narrow(datawriter);
    if (hw_writer == NULL)
    {
        printf("failed datawriter narrow\n");
        goto done;
    }

    sample = myModule_myTypeTypeSupport::create_data();
    if (sample == NULL)
    {
        printf("failed myModule_myType_create\n");
        return -1;
    }

    for (i = 0;
    (application->count > 0 && i < application->count) ||
    (application->count == 0);
    ++i)
    {
        /* TODO set sample attributes here */
        
        // LAB #1 - set some values in the sample before we send it
        sample->id =1234;
        sample->value1 = i;
        sample->name = "DonGochenour";

        retcode = hw_writer->write(*sample, DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write sample\n");
        } 
        else
        {
            printf("Written sample %d\n",(i+1));
        } 

        OSAPI_Thread_sleep(application->sleep_time);
    }

    done:

    if (application != NULL)
    {
        delete application;
    }

    if (sample != NULL)
    {
        myModule_myTypeTypeSupport::delete_data(sample);
    } 

    return 0;
}

#if !(defined(RTI_VXWORKS) && !defined(__RTP__))
int
main(int argc, char **argv)
{

    DDS_Long i = 0;
    DDS_Long domain_id = 0;
    char *peer = NULL;
    char *udp_intf = NULL;
    DDS_Long sleep_time = 1000;
    DDS_Long count = 0;

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

    return publisher_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#elif defined(RTI_VXWORKS)
int
publisher_main(void)
{
    /* Explicitly configure args below */
    DDS_Long i = 0;
    DDS_Long domain_id = 44;
    char *peer = "10.10.65.104";
    char *udp_intf = NULL;
    DDS_Long sleep_time = 1000;
    DDS_Long count = 0;

    return publisher_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#endif
