/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from quickstart.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "quickstart.h"

#ifndef UNUSED_ARG
#define UNUSED_ARG(x) (void)(x)
#endif

#include "dds_c/dds_c_typecode.h"
/*** SOURCE_BEGIN ***/

namespace myModule {

    myType *
    myType_create(void)
    {
        myType* sample;
        OSAPI_Heap_allocate_struct(&sample, myType);
        if (sample != NULL) {
            if (!myType_initialize(sample)) {
                OSAPI_Heap_free_struct(sample);
                sample = NULL;
            }
        }
        return sample;
    }
    void
    myType_delete(myType*sample)
    {
        if (sample != NULL) {
            /* myType_finalize() always 
            returns RTI_TRUE when called with sample != NULL */
            myType_finalize(sample);
            OSAPI_Heap_free_struct(sample);
        }
    }

    /* ========================================================================= */
    const char *myTypeTYPENAME = "myModule::myType";

    #ifndef NDDS_STANDALONE_TYPE
    DDS_TypeCode* myType_get_typecode()
    {
        static RTIBool is_initialized = RTI_FALSE;

        static DDS_TypeCode myType_g_tc_name_string = DDS_INITIALIZE_STRING_TYPECODE((128));

        static DDS_TypeCode_Member myType_g_tc_members[4]=
        {

            {
                (char *)"id",/* Member name */
                {
                    0,/* Representation ID */
                    DDS_BOOLEAN_FALSE,/* Is a pointer? */
                    -1, /* Bitfield bits */
                    NULL/* Member type code is assigned later */
                },
                0, /* Ignored */
                0, /* Ignored */
                0, /* Ignored */
                NULL, /* Ignored */
                RTI_CDR_KEY_MEMBER , /* Is a key? */
                DDS_PUBLIC_MEMBER,/* Member visibility */
                1,
                NULL, /* Ignored */
                RTICdrTypeCodeAnnotations_INITIALIZER
            }, 
            {
                (char *)"value1",/* Member name */
                {
                    1,/* Representation ID */
                    DDS_BOOLEAN_FALSE,/* Is a pointer? */
                    -1, /* Bitfield bits */
                    NULL/* Member type code is assigned later */
                },
                0, /* Ignored */
                0, /* Ignored */
                0, /* Ignored */
                NULL, /* Ignored */
                RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                DDS_PUBLIC_MEMBER,/* Member visibility */
                1,
                NULL, /* Ignored */
                RTICdrTypeCodeAnnotations_INITIALIZER
            }, 
            {
                (char *)"state",/* Member name */
                {
                    2,/* Representation ID */
                    DDS_BOOLEAN_FALSE,/* Is a pointer? */
                    -1, /* Bitfield bits */
                    NULL/* Member type code is assigned later */
                },
                0, /* Ignored */
                0, /* Ignored */
                0, /* Ignored */
                NULL, /* Ignored */
                RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                DDS_PUBLIC_MEMBER,/* Member visibility */
                1,
                NULL, /* Ignored */
                RTICdrTypeCodeAnnotations_INITIALIZER
            }, 
            {
                (char *)"name",/* Member name */
                {
                    3,/* Representation ID */
                    DDS_BOOLEAN_FALSE,/* Is a pointer? */
                    -1, /* Bitfield bits */
                    NULL/* Member type code is assigned later */
                },
                0, /* Ignored */
                0, /* Ignored */
                0, /* Ignored */
                NULL, /* Ignored */
                RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                DDS_PUBLIC_MEMBER,/* Member visibility */
                1,
                NULL, /* Ignored */
                RTICdrTypeCodeAnnotations_INITIALIZER
            }
        };

        static DDS_TypeCode myType_g_tc =
        {{
                DDS_TK_STRUCT, /* Kind */
                DDS_BOOLEAN_FALSE, /* Ignored */
                -1, /*Ignored*/
                (char *)"myModule::myType", /* Name */
                NULL, /* Ignored */      
                0, /* Ignored */
                0, /* Ignored */
                NULL, /* Ignored */
                4, /* Number of members */
                myType_g_tc_members, /* Members */
                DDS_VM_NONE, /* Ignored */
                RTICdrTypeCodeAnnotations_INITIALIZER,
                DDS_BOOLEAN_TRUE, /* _isCopyable */
                NULL, /* _sampleAccessInfo: assigned later */
                NULL /* _typePlugin: assigned later */
            }}; /* Type code for myType*/

        if (is_initialized) {
            return &myType_g_tc;
        }

        myType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

        myType_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
        myType_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
        myType_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;
        myType_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&myType_g_tc_name_string;

        /* Initialize the values for member annotations. */
        myType_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
        myType_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
        myType_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
        myType_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
        myType_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
        myType_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

        myType_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
        myType_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
        myType_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
        myType_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
        myType_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
        myType_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

        myType_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
        myType_g_tc_members[2]._annotations._defaultValue._u.boolean_value = 0;

        myType_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
        myType_g_tc_members[3]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

        myType_g_tc._data._sampleAccessInfo =
        myType_get_sample_access_info();
        myType_g_tc._data._typePlugin =
        myType_get_type_plugin_info();    

        is_initialized = RTI_TRUE;

        return &myType_g_tc;
    }

    RTIXCdrSampleAccessInfo *myType_get_sample_access_info()
    {
        static RTIBool is_initialized = RTI_FALSE;

        myModule::myType *sample;

        static RTIXCdrMemberAccessInfo myType_g_memberAccessInfos[4] =
        {RTIXCdrMemberAccessInfo_INITIALIZER};

        static RTIXCdrSampleAccessInfo myType_g_sampleAccessInfo = 
        RTIXCdrSampleAccessInfo_INITIALIZER;

        if (is_initialized) {
            return (RTIXCdrSampleAccessInfo*) &myType_g_sampleAccessInfo;
        }

        RTIXCdrHeap_allocateStruct(
            &sample, 
            myModule::myType);
        if (sample == NULL) {
            return NULL;
        }

        myType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
        (RTIXCdrUnsignedLong) ((char *)&sample->id - (char *)sample);

        myType_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
        (RTIXCdrUnsignedLong) ((char *)&sample->value1 - (char *)sample);

        myType_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
        (RTIXCdrUnsignedLong) ((char *)&sample->state - (char *)sample);

        myType_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
        (RTIXCdrUnsignedLong) ((char *)&sample->name - (char *)sample);

        myType_g_sampleAccessInfo.memberAccessInfos = 
        myType_g_memberAccessInfos;

        {
            size_t candidateTypeSize = sizeof(myType);

            if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
                myType_g_sampleAccessInfo.typeSize[0] =
                RTIXCdrUnsignedLong_MAX;
            } else {
                myType_g_sampleAccessInfo.typeSize[0] =
                (RTIXCdrUnsignedLong) candidateTypeSize;
            }
        }

        myType_g_sampleAccessInfo.languageBinding = 
        RTI_XCDR_TYPE_BINDING_CPP ;

        RTIXCdrHeap_freeStruct(sample);
        is_initialized = RTI_TRUE;
        return (RTIXCdrSampleAccessInfo*) &myType_g_sampleAccessInfo;
    }

    RTIXCdrTypePlugin *myType_get_type_plugin_info()
    {
        static RTIXCdrTypePlugin myType_g_typePlugin = 
        {
            NULL, /* serialize */
            NULL, /* serialize_key */
            NULL, /* deserialize_sample */
            NULL, /* deserialize_key_sample */
            NULL, /* skip */
            NULL, /* get_serialized_sample_size */
            NULL, /* get_serialized_sample_max_size_ex */
            NULL, /* get_serialized_key_max_size_ex */
            NULL, /* get_serialized_sample_min_size */
            NULL, /* serialized_sample_to_key */
            (RTIXCdrTypePluginInitializeSampleFunction) 
            myModule::myType_initialize_ex,
            NULL,
            (RTIXCdrTypePluginFinalizeSampleFunction)
            myModule::myType_finalize_w_return,
            NULL
        };

        return &myType_g_typePlugin;
    }
    #endif

    RTIBool myType_initialize(
        myType* sample) {
        return myModule::myType_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
    }

    RTIBool myType_initialize_ex(
        myType* sample,RTIBool allocatePointers, RTIBool allocateMemory)
    {

        struct DDS_TypeAllocationParams_t allocParams =
        DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

        allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
        allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

        return myModule::myType_initialize_w_params(
            sample,&allocParams);

    }

    RTIBool myType_initialize_w_params(
        myType* sample, const struct DDS_TypeAllocationParams_t * allocParams)
    {

        if (sample == NULL) {
            return RTI_FALSE;
        }
        if (allocParams == NULL) {
            return RTI_FALSE;
        }

        sample->id = 0;

        sample->value1 = 0;

        sample->state = 0;

        if (allocParams->allocate_memory) {
            const DDS_Char stringValue[] = "";
            const DDS_String temp = (const DDS_String)stringValue;  
            sample->name = DDS_String_alloc((128));  
            if (!CDR_String_copy(&sample->name, &temp, (128)))
            {
                return RTI_FALSE;
            }
            if (sample->name == NULL) {
                return RTI_FALSE;
            }
        } else {
            if (sample->name != NULL) {
                const DDS_Char stringValue[] = "";
                const DDS_String temp = (const DDS_String)stringValue;  
                if (!CDR_String_copy(&sample->name, &temp, (128)))
                {
                    return RTI_FALSE;
                }
                if (sample->name == NULL) {
                    return RTI_FALSE;
                }
            }
        }

        return RTI_TRUE;
    }

    RTIBool myType_finalize(
        myType* sample)
    {

        myModule::myType_finalize_ex(sample,RTI_TRUE);
        return RTI_TRUE;
    }

    RTIBool myType_finalize_w_return(
        myType* sample)
    {

        myModule::myType_finalize_ex(sample,RTI_TRUE);
        return RTI_TRUE;
    }

    void myType_finalize_ex(
        myType* sample,RTIBool deletePointers)
    {
        struct DDS_TypeDeallocationParams_t deallocParams =
        DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

        if (sample==NULL) {
            return;
        } 

        deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

        myModule::myType_finalize_w_params(
            sample,&deallocParams);
    }

    void myType_finalize_w_params(
        myType* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
    {

        if (sample==NULL) {
            return;
        }

        if (deallocParams == NULL) {
            return;
        }

        if (sample->name != NULL) {
            DDS_String_free(sample->name);
            sample->name=NULL;

        }
    }

    void myType_finalize_optional_members(
        myType* sample, RTIBool deletePointers)
    {
        struct DDS_TypeDeallocationParams_t deallocParamsTmp =
        DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
        struct DDS_TypeDeallocationParams_t * deallocParams =
        &deallocParamsTmp;

        if (sample==NULL) {
            return;
        } 
        if (deallocParams) {} /* To avoid warnings */

        deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
        deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    }

    RTIBool myType_copy(
        myType* dst,
        const myType* src)
    {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        DDS_Primitive_copy (&dst->id, &src->id);
        DDS_Primitive_copy (&dst->value1, &src->value1);
        DDS_Primitive_copy (&dst->state, &src->state);
        if (!DDS_String_copy (
            &dst->name, &src->name, 
            (128) + 1)){
            return RTI_FALSE;
        }

        return RTI_TRUE;

    }

    /**
    * <<IMPLEMENTATION>>
    *
    * Defines:  TSeq, T
    *
    * Configure and implement 'myType' sequence class.
    */
    #define REDA_SEQUENCE_USER_API
    #define T myType
    #define TSeq myTypeSeq

    #define T_initialize myModule::myType_initialize

    #define T_finalize   myModule::myType_finalize
    #define T_copy       myModule::myType_copy

    #include "reda/reda_sequence_defn.h"
    #undef T_copy
    #undef T_finalize
    #undef T_initialize

    #define REDA_SEQUENCE_USER_API
    #define T myType
    #define TSeq myTypeSeq
    #include "dds_cpp/dds_cpp_sequence_defn.hxx"

    #undef T_copy
    #undef T_finalize

    #undef T_initialize

    #undef TSeq
    #undef T

} /* namespace myModule  */

