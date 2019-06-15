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

myModule_myType *
myModule_myType_create(void)
{
    myModule_myType* sample;
    OSAPI_Heap_allocate_struct(&sample, myModule_myType);
    if (sample != NULL) {
        if (!myModule_myType_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}
void
myModule_myType_delete(myModule_myType*sample)
{
    if (sample != NULL) {
        /* myModule_myType_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        myModule_myType_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}

/* ========================================================================= */
const char *myModule_myTypeTYPENAME = "myModule::myType";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* myModule_myType_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode myModule_myType_g_tc_name_string = DDS_INITIALIZE_STRING_TYPECODE((128));

    static DDS_TypeCode_Member myModule_myType_g_tc_members[4]=
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

    static DDS_TypeCode myModule_myType_g_tc =
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
            myModule_myType_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for myModule_myType*/

    if (is_initialized) {
        return &myModule_myType_g_tc;
    }

    myModule_myType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    myModule_myType_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    myModule_myType_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    myModule_myType_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;
    myModule_myType_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&myModule_myType_g_tc_name_string;

    /* Initialize the values for member annotations. */
    myModule_myType_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    myModule_myType_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
    myModule_myType_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    myModule_myType_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    myModule_myType_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    myModule_myType_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    myModule_myType_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    myModule_myType_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
    myModule_myType_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    myModule_myType_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    myModule_myType_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    myModule_myType_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    myModule_myType_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
    myModule_myType_g_tc_members[2]._annotations._defaultValue._u.boolean_value = 0;

    myModule_myType_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    myModule_myType_g_tc_members[3]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    myModule_myType_g_tc._data._sampleAccessInfo =
    myModule_myType_get_sample_access_info();
    myModule_myType_g_tc._data._typePlugin =
    myModule_myType_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &myModule_myType_g_tc;
}

RTIXCdrSampleAccessInfo *myModule_myType_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    myModule_myType *sample;

    static RTIXCdrMemberAccessInfo myModule_myType_g_memberAccessInfos[4] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo myModule_myType_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &myModule_myType_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        myModule_myType);
    if (sample == NULL) {
        return NULL;
    }

    myModule_myType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->id - (char *)sample);

    myModule_myType_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->value1 - (char *)sample);

    myModule_myType_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->state - (char *)sample);

    myModule_myType_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->name - (char *)sample);

    myModule_myType_g_sampleAccessInfo.memberAccessInfos = 
    myModule_myType_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(myModule_myType);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            myModule_myType_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            myModule_myType_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    myModule_myType_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &myModule_myType_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *myModule_myType_get_type_plugin_info()
{
    static RTIXCdrTypePlugin myModule_myType_g_typePlugin = 
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
        myModule_myType_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        myModule_myType_finalize_w_return,
        NULL
    };

    return &myModule_myType_g_typePlugin;
}
#endif

RTIBool myModule_myType_initialize(
    myModule_myType* sample) {
    return myModule_myType_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool myModule_myType_initialize_ex(
    myModule_myType* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return myModule_myType_initialize_w_params(
        sample,&allocParams);

}

RTIBool myModule_myType_initialize_w_params(
    myModule_myType* sample, const struct DDS_TypeAllocationParams_t * allocParams)
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

RTIBool myModule_myType_finalize(
    myModule_myType* sample)
{

    myModule_myType_finalize_ex(sample,RTI_TRUE);
    return RTI_TRUE;
}

RTIBool myModule_myType_finalize_w_return(
    myModule_myType* sample)
{

    myModule_myType_finalize_ex(sample,RTI_TRUE);
    return RTI_TRUE;
}

void myModule_myType_finalize_ex(
    myModule_myType* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    myModule_myType_finalize_w_params(
        sample,&deallocParams);
}

void myModule_myType_finalize_w_params(
    myModule_myType* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
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

void myModule_myType_finalize_optional_members(
    myModule_myType* sample, RTIBool deletePointers)
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

RTIBool myModule_myType_copy(
    myModule_myType* dst,
    const myModule_myType* src)
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
* Configure and implement 'myModule_myType' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T myModule_myType
#define TSeq myModule_myTypeSeq

#define T_initialize myModule_myType_initialize

#define T_finalize   myModule_myType_finalize
#define T_copy       myModule_myType_copy

#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

#define REDA_SEQUENCE_USER_API
#define T myModule_myType
#define TSeq myModule_myTypeSeq
#include "dds_cpp/dds_cpp_sequence_defn.hxx"

#undef T_copy
#undef T_finalize

#undef T_initialize

#undef TSeq
#undef T

