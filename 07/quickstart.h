/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from quickstart.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#ifndef quickstart_214727359_h
#define quickstart_214727359_h

#ifndef rti_me_cpp_hxx
#include "rti_me_cpp.hxx"
#endif

#include "dds_c/dds_c_typecode.h"

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

static const DDS_String myModule_my_topic_name = "myTopic";

extern "C" {

    extern const char *myModule_myTypeTYPENAME;

}

struct myModule_myTypeSeq;
#ifndef NDDS_STANDALONE_TYPE
class myModule_myTypeTypeSupport;
class myModule_myTypeDataWriter;
class myModule_myTypeDataReader;
#endif
class myModule_myType 
{
  public:
    typedef struct myModule_myTypeSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef myModule_myTypeTypeSupport TypeSupport;
    typedef myModule_myTypeDataWriter DataWriter;
    typedef myModule_myTypeDataReader DataReader;
    #endif

    DDS_Long   id ;
    DDS_Long   value1 ;
    DDS_Boolean   state ;
    DDS_String   name ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* myModule_myType_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *myModule_myType_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *myModule_myType_get_sample_access_info(void);
#endif

#define REDA_SEQUENCE_USER_API
#define T myModule_myType
#define TSeq myModule_myTypeSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>
#define REDA_SEQUENCE_USER_API
#define T myModule_myType
#define TSeq myModule_myTypeSeq
#define REDA_SEQUENCE_EXCLUDE_STRUCT
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

NDDSUSERDllExport extern myModule_myType*
myModule_myType_create();

NDDSUSERDllExport extern void
myModule_myType_delete(myModule_myType* sample);

NDDSUSERDllExport
RTIBool myModule_myType_initialize(
    myModule_myType* self);

NDDSUSERDllExport
RTIBool myModule_myType_initialize_ex(
    myModule_myType* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool myModule_myType_initialize_w_params(
    myModule_myType* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool myModule_myType_finalize(
    myModule_myType* self);

NDDSUSERDllExport
RTIBool myModule_myType_finalize_w_return(
    myModule_myType* self);

NDDSUSERDllExport
void myModule_myType_finalize_ex(
    myModule_myType* self,RTIBool deletePointers);

NDDSUSERDllExport
void myModule_myType_finalize_w_params(
    myModule_myType* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void myModule_myType_finalize_optional_members(
    myModule_myType* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool myModule_myType_copy(
    myModule_myType* dst,
    const myModule_myType* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#ifndef NDDS_STANDALONE_TYPE
#endif

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* quickstart */

