/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from quickstart.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "quickstart.h"
#include "reda/reda_bufferpool.h"
#include "xcdr/xcdr_interpreter.h"
#include "dds_c/dds_c_xcdr_type_plugin.h"
#include "quickstartPlugin.h"
#include "quickstartSupport.h"

/*** SOURCE_BEGIN ***/
#ifndef UNUSED_ARG
#define UNUSED_ARG(x) (void)(x)
#endif

namespace myModule {

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */

    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */

    /* --------------------------------------------------------------------------
    Typed-endpoint support for C++:
    * -------------------------------------------------------------------------- */

    void* 
    myTypePlugin_create_typed_datawriter(void *writer)
    {
        /* This function is only called from DDS_Publisher_create_datawriter
        * so writer is guaranteed to have a valid (i.e. non-NULL) value 
        */
        DDSDataWriter *cpp_writer = 
        new myTypeDataWriter((DDS_DataWriter*)writer);

        return cpp_writer;   
    }

    #ifndef RTI_CERT
    void 
    myTypePlugin_delete_typed_datawriter(void *wrapper)
    {
        /* This function is only called from DDS_Publisher_create_datawriter
        * and DDS_Publisher_delete_datawriter so wrapper is guaranteed to have
        * a valid (i.e. non-NULL) value 
        */
        DDSDataWriter_impl *cpp_writer = (DDSDataWriter_impl *) wrapper;

        myTypeDataWriter *t_writer = 
        static_cast<myTypeDataWriter *>(cpp_writer);

        delete t_writer;
    }
    #endif

    void* 
    myTypePlugin_create_typed_datareader(void *reader)
    {
        /* This function is only called from DDS_Subscriber_create_datareader
        * so reader is guaranteed to have a valid (i.e. non-NULL) value 
        */
        DDSDataReader *cpp_reader = 
        new myTypeDataReader((DDS_DataReader*)reader);

        return cpp_reader;      
    }

    #ifndef RTI_CERT
    void
    myTypePlugin_delete_typed_datareader(void *wrapper)
    {
        /* This function is only called from DDS_Subscriber_create_datareader
        * and DDS_Subscriber_delete_datareader so wrapper is guaranteed to have
        * a valid (i.e. non-NULL) value 
        */
        DDSDataReader_impl *cpp_reader = (DDSDataReader_impl *) wrapper;

        myTypeDataReader *t_reader = 
        static_cast<myTypeDataReader *>(cpp_reader);

        delete t_reader;
    }
    #endif

    /* --------------------------------------------------------------------------
    *  Sample Support functions:
    * -------------------------------------------------------------------------- */
    RTI_BOOL
    myTypePlugin_create_sample(struct DDS_TypePlugin *plugin,
    void **sample)
    {
        UNUSED_ARG(plugin);

        *sample = (void *) myType_create();
        return (*sample != NULL);
    }

    #ifndef RTI_CERT
    RTI_BOOL
    myTypePlugin_delete_sample(struct DDS_TypePlugin *plugin, 
    void *sample)
    {
        UNUSED_ARG(plugin);

        myType_delete((myType *) sample);
        return RTI_TRUE;
    }
    #endif

    RTI_BOOL 
    myTypePlugin_copy_sample(struct DDS_TypePlugin *plugin, 
    void *dst, 
    const void *src)
    {
        UNUSED_ARG(plugin);

        return myType_copy(
            (myType*)dst,
            (const myType*)src);
    }
    /* --------------------------------------------------------------------------
    *  Type myType Plugin Instantiation
    * -------------------------------------------------------------------------- */

    NDDSCDREncapsulation myTypeEncapsulationKind[] =
    { 
        {
            DDS_ENCAPSULATION_ID_CDR_LE,
            DDS_ENCAPSULATION_ID_CDR_BE,
            0
        }
    };

    NDDSCDREncapsulation myTypeV2EncapsulationKind[] =
    { 
        {

            DDS_ENCAPSULATION_ID_XCDR2_A_LE,
            DDS_ENCAPSULATION_ID_XCDR2_A_BE,
            0

        }
    };

    MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
    myTypeTypePlugin_initialize_sample(struct DDS_TypePlugin *plugin, void *buffer)
    {
        UNUSED_ARG(plugin);
        return myType_initialize((myType*)buffer);
    }

    RTI_PRIVATE RTI_UINT32 
    myType_get_user_sample_size(
        struct DDS_TypePlugin *tp)
    {
        UNUSED_ARG(tp);        
        return sizeof(myType);
    }

    MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
    myType_cdr_initialize(void *init_config, void *buffer)
    {
        struct DDS_TypePluginDefault *plugin = (struct DDS_TypePluginDefault*)init_config;
        void *sample;
        struct DDS_TypePluginSampleHolder *sh = (struct DDS_TypePluginSampleHolder*)buffer;

        if (!myTypePlugin_create_sample(&plugin->_parent,&sample))
        {
            return RTI_FALSE;
        }

        sh->sample = sample;

        return RTI_TRUE;
    }

    MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
    myType_cdr_finalize(void *finalize_config, void *buffer)
    {
        struct DDS_TypePluginDefault *plugin = (struct DDS_TypePluginDefault*)finalize_config;
        struct DDS_TypePluginSampleHolder *sh = (struct DDS_TypePluginSampleHolder*)buffer;

        if (!myTypePlugin_delete_sample(&plugin->_parent,sh->sample))
        {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }

    RTI_PRIVATE void 
    myTypeTypePlugin_return_sample(
        struct DDS_TypePlugin *tp,
        struct DDS_TypePluginSampleHolder *sample)
    {
        myType_finalize_optional_members((myType*)sample->sample, RTI_FALSE);
        XCDR_GenericStreamPlugin_return_sample(tp, sample);
    }

    RTI_PRIVATE struct DDS_TypeMemoryPlugin*
    myTypeXTypesHeapPlugin_create(struct DDS_TypePlugin *tp,
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_TypePluginMode_T endpoint_mode,
    DDS_TypePluginEndpoint *endpoint,
    DDS_TypePluginEndpointQos *qos)
    {
        return DDS_XTypesHeapPlugin_create(
            tp,
            participant,
            dp_qos,
            endpoint_mode,
            endpoint,
            qos,
            NULL,
            NULL,
            myModule::myType_cdr_initialize,
            myModule::myType_cdr_finalize,
            sizeof(myType),
            RTI_FALSE
            );
    }

    RTI_PRIVATE struct DDS_TypeMemoryI myType_fv_XTypesHeapPluginI =
    {
        RTI_MEMORY_MANAGER_HEAP,
        RTI_MEMORY_TYPE_HEAP,
        myTypePlugin_create_sample,
        #ifndef RTI_CERT
        myTypePlugin_delete_sample,
        #else
        NULL,
        #endif
        NULL, /* get_address */
        NULL, /* return_address */
        NULL,
        DDS_XTypesHeapPlugin_get_sample_state,
        DDS_XTypesHeapPlugin_set_sample_state,
        DDS_XTypesHeapPlugin_is_owner,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        myTypeXTypesHeapPlugin_create,
        DDS_XTypesHeapPlugin_delete
    };	

    RTI_PRIVATE DDS_Boolean 
    myType_on_type_registered(struct DDS_TypeImpl* type_impl)
    {
        struct RTIXCdrInterpreterPrograms *programs = NULL;
        struct RTIXCdrInterpreterProgramsGenProperty programProperty =
        RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;

        programProperty.resolveAlias = RTI_XCDR_TRUE;
        programProperty.inlineStruct = RTI_XCDR_TRUE;
        programProperty.optimizeEnum = RTI_XCDR_TRUE;

        programs = RTIXCdrInterpreterPrograms_new(
            (RTIXCdrTypeCode *)myType_get_typecode(),
            &programProperty,
            RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN
            );

        if (programs == NULL)
        {
            return DDS_BOOLEAN_FALSE;
        }

        DDS_TypeImpl_set_programs(type_impl, programs);
        DDS_TypeImpl_set_typecode(type_impl,  myType_get_typecode());

        return DDS_BOOLEAN_TRUE;
    }
    RTI_PRIVATE DDS_Boolean 
    myType_on_type_unregistered(struct DDS_TypeImpl* type_impl)
    {
        struct RTIXCdrInterpreterPrograms *programs = NULL;
        programs = DDS_TypeImpl_get_programs(type_impl);

        if (programs != NULL) 
        {
            RTIXCdrInterpreterPrograms_delete(programs);
        }
        DDS_TypeImpl_set_programs(type_impl, NULL); 

        return DDS_BOOLEAN_TRUE;   
    }

    RTI_PRIVATE 
    struct DDS_TypeEncapsulationI myType_fv_XCDRv1PluginI =
    {
        DDS_XCDR_DATA_REPRESENTATION,
        NULL,
        myTypeEncapsulationKind,
        RTI_MEMORY_TYPE_HEAP,
        RTI_MEMORY_MANAGER_HEAP,
        NULL,
        NULL,
        XCDR_GenericStreamPlugin_get_buffer,
        XCDR_GenericStreamPlugin_return_buffer,
        XCDR_GenericStreamPlugin_get_sample,
        myTypeTypePlugin_return_sample,
        XCDR_GenericStreamPlugin_serialize,
        XCDR_GenericStreamPlugin_deserialize,
        XCDRv1_StreamPlugin_get_serialized_sample_size,
        XCDRv1_StreamPlugin_create,
        XCDRv1_StreamPlugin_delete,
    };

    RTI_PRIVATE struct DDS_TypeEncapsulationI myType_fv_XCDRv2PluginI =
    {
        DDS_XCDR2_DATA_REPRESENTATION,
        NULL,
        myTypeV2EncapsulationKind,
        RTI_MEMORY_TYPE_HEAP,
        RTI_MEMORY_MANAGER_HEAP,
        NULL,
        NULL,
        XCDR_GenericStreamPlugin_get_buffer,
        XCDR_GenericStreamPlugin_return_buffer,
        XCDR_GenericStreamPlugin_get_sample,

        myTypeTypePlugin_return_sample,   
        XCDR_GenericStreamPlugin_serialize,
        XCDR_GenericStreamPlugin_deserialize,
        XCDRv2_StreamPlugin_get_serialized_sample_size,
        XCDRv2_StreamPlugin_create,
        XCDRv2_StreamPlugin_delete,
    };

    RTI_PRIVATE struct DDS_TypeEncapsulationI *myType_fv_WirePlugins[] =
    {
        &myType_fv_XCDRv2PluginI,
        &myType_fv_XCDRv1PluginI,
        NULL
    };

    RTI_PRIVATE struct DDS_TypeMemoryI *myType_fv_MemoryPlugins[] =
    {
        &myType_fv_XTypesHeapPluginI,

        NULL
    };

    RTI_PRIVATE struct DDS_TypePlugin*
    myTypeTypePlugin_create_plugin(
        DDS_DomainParticipant *participant,
        struct DDS_DomainParticipantQos *dp_qos,
        DDS_TypePluginMode_T endpoint_mode,
        DDS_TypePluginEndpoint *endpoint,
        DDS_TypePluginEndpointQos *qos,
        struct DDS_TypePluginProperty *const property);
    RTI_PRIVATE RTI_BOOL
    myTypeTypePlugin_delete_plugin(struct DDS_TypePlugin *plugin);

    RTI_PRIVATE struct DDS_TypePluginI myType_fv_TypePluginI =
    {
        /**************************************************************************
        *                   Type information functions
        **************************************************************************/

        NULL,                       /* DDS_TypeCode_t* */
        NDDS_TYPEPLUGIN_USER_KEY,   /* NDDS_TypePluginKeyKind */

        NDDS_TYPEPLUGIN_EH_LOCATION_PAYLOAD,
        myType_get_user_sample_size,   
        RTI_MEMORY_TYPE_HEAP,
        XCDR_GenericTypePlugin_instance_to_keyhash,
        myModule::myTypePlugin_copy_sample,

        myTypeTypePlugin_initialize_sample,

        XCDR_GenericTypePlugin_serialize_key,
        XCDR_GenericTypePlugin_deserialize_key,
        XCDR_GenericTypelugin_get_serialized_key_size,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        myType_fv_MemoryPlugins,
        myType_fv_WirePlugins,

        /**************************************************************************
        *       Helper APIs to create language binding wrapper Functions
        **************************************************************************/

        myModule::myTypePlugin_create_typed_datawriter,
        #ifndef RTI_CERT
        myModule::myTypePlugin_delete_typed_datawriter,
        #else
        NULL,
        #endif
        myModule::myTypePlugin_create_typed_datareader,
        #ifndef RTI_CERT
        myModule::myTypePlugin_delete_typed_datareader,
        #else
        NULL,
        #endif
        myModule::myTypeTypePlugin_create_plugin,
        myModule::myTypeTypePlugin_delete_plugin,
        myType_on_type_registered,
        myType_on_type_unregistered,

    };

    /* --------------------------------------------------------------------------
    *  Type myType Plugin Methods
    * -------------------------------------------------------------------------- */

    struct DDS_TypePluginI*
    myTypeTypePlugin_get(void) 
    { 
        return &myType_fv_TypePluginI;
    } 

    RTI_PRIVATE struct DDS_TypePlugin*
    myTypeTypePlugin_create_plugin(
        DDS_DomainParticipant *participant,
        struct DDS_DomainParticipantQos *dp_qos,
        DDS_TypePluginMode_T endpoint_mode,
        DDS_TypePluginEndpoint *endpoint,
        DDS_TypePluginEndpointQos *qos,
        struct DDS_TypePluginProperty *const property)
    {
        return DDS_TypePluginDefault_create(&myType_fv_TypePluginI,
        participant,dp_qos,
        endpoint_mode,endpoint,qos,
        property);
    }

    RTI_PRIVATE RTI_BOOL
    myTypeTypePlugin_delete_plugin(struct DDS_TypePlugin *plugin)
    {
        return DDS_TypePluginDefault_delete(plugin);
    }

    struct DDS_TypePlugin*
    myTypeWriterTypePlugin_create(
        DDS_DomainParticipant *participant,
        struct DDS_DomainParticipantQos *dp_qos,
        DDS_DataWriter *writer,
        struct DDS_DataWriterQos *qos,
        struct DDS_TypePluginProperty *property)
    {
        return DDS_TypePlugin_create_w_intf(
            &myType_fv_TypePluginI,
            participant,dp_qos,
            DDS_TYPEPLUGIN_MODE_WRITER,
            (DDS_TypePluginEndpoint*)writer,
            (DDS_TypePluginEndpointQos*)qos,
            property);
    }

    struct DDS_TypePlugin*
    myTypeReaderTypePlugin_create(
        DDS_DomainParticipant *participant,
        struct DDS_DomainParticipantQos *dp_qos,
        DDS_DataReader *reader,
        struct DDS_DataReaderQos *qos,
        struct DDS_TypePluginProperty *property)
    {
        return DDS_TypePlugin_create_w_intf(
            &myType_fv_TypePluginI,
            participant,dp_qos,
            DDS_TYPEPLUGIN_MODE_READER,
            (DDS_TypePluginEndpoint*)reader,
            (DDS_TypePluginEndpointQos*)qos,
            property);
    }

    const char*
    myTypeTypePlugin_get_default_type_name(void) 
    { 
        return myTypeTYPENAME;
    } 

    NDDS_TypePluginKeyKind 
    myTypeI_get_key_kind(void)
    {
        return myType_fv_TypePluginI.key_kind;
    }

} /* namespace myModule  */

