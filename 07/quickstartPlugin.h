/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from quickstart.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#ifndef quickstartPlugin_214727359_h
#define quickstartPlugin_214727359_h

#include "quickstart.h"

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace myModule {

    struct myTypeTypePlugin;

    NDDSUSERDllExport extern RTI_BOOL
    myTypeTypePlugin_delete(struct DDS_TypePlugin *self);

    NDDSUSERDllExport extern struct DDS_TypePlugin*
    myTypeWriterTypePlugin_create(
        DDS_DomainParticipant *participant,
        struct DDS_DomainParticipantQos *dp_qos,
        DDS_DataWriter *writer,
        struct DDS_DataWriterQos *qos,
        struct DDS_TypePluginProperty *property);

    NDDSUSERDllExport extern struct DDS_TypePlugin*
    myTypeReaderTypePlugin_create(
        DDS_DomainParticipant *participant,
        struct DDS_DomainParticipantQos *dp_qos,
        DDS_DataReader *reader,
        struct DDS_DataReaderQos *qos,
        struct DDS_TypePluginProperty *property);

    NDDSUSERDllExport extern struct DDS_TypePluginI*
    myTypeTypePlugin_get(void);
    NDDSUSERDllExport extern const char*
    myTypeTypePlugin_get_default_type_name(void);
    NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
    myTypeI_get_key_kind();
    /* --------------------------------------------------------------------------
    Untyped interfaces to the typed sample management functions
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL
    myTypePlugin_create_sample(
        struct DDS_TypePlugin *plugin, void **sample);

    #ifndef RTI_CERT
    NDDSUSERDllExport extern RTI_BOOL 
    myTypePlugin_delete_sample(
        struct DDS_TypePlugin *plugin, void *sample);
    #endif

    NDDSUSERDllExport extern RTI_BOOL 
    myTypePlugin_copy_sample(
        struct DDS_TypePlugin *plugin, void *dst, const void *src);

    /* --------------------------------------------------------------------------
    (De)Serialize functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    myType_cdr_serialize(struct DDS_TypePlugin *plugin, 
    struct CDR_Stream_t *stream, 
    const void *void_sample,
    DDS_InstanceHandle_t *destination);

    NDDSUSERDllExport extern RTI_BOOL 
    myType_cdr_deserialize(struct DDS_TypePlugin *plugin,
    void *void_sample,
    struct CDR_Stream_t *stream,
    DDS_InstanceHandle_t *source); 

    NDDSUSERDllExport extern RTI_UINT32
    myType_get_serialized_sample_size(
        struct DDS_TypePlugin *plugin,
        RTI_UINT32 current_alignment);
    /* --------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------- */
    NDDSUSERDllExport extern RTI_BOOL 
    myType_cdr_serialize_key(struct DDS_TypePlugin *plugin,
    struct CDR_Stream_t *keystream, 
    const void *sample,
    DDS_InstanceHandle_t *destination);

    NDDSUSERDllExport extern RTI_BOOL 
    myType_cdr_deserialize_key(
        struct DDS_TypePlugin *plugin,
        void *sample,
        struct CDR_Stream_t *keystream,
        DDS_InstanceHandle_t *source);

    NDDSUSERDllExport extern RTI_UINT32
    myType_get_serialized_key_size(
        struct DDS_TypePlugin *plugin,
        RTI_UINT32 current_alignment);

    NDDSUSERDllExport extern RTI_BOOL 
    myType_instance_to_keyhash(
        struct DDS_TypePlugin *plugin,
        struct CDR_Stream_t *stream, 
        DDS_KeyHash_t *keyHash, 
        const void *instance,
        DDS_EncapsulationId_t id);

} /* namespace myModule  */

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* quickstartPlugin_214727359_h */

