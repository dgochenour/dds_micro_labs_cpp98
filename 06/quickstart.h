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

namespace myModule {

    static const DDS_String my_topic_name = "myTopic";

    extern const char *myTypeTYPENAME;

    struct myTypeSeq;
    #ifndef NDDS_STANDALONE_TYPE
    class myTypeTypeSupport;
    class myTypeDataWriter;
    class myTypeDataReader;
    #endif
    class myType 
    {
      public:
        typedef struct myTypeSeq Seq;
        #ifndef NDDS_STANDALONE_TYPE
        typedef myTypeTypeSupport TypeSupport;
        typedef myTypeDataWriter DataWriter;
        typedef myTypeDataReader DataReader;
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
    NDDSUSERDllExport DDS_TypeCode* myType_get_typecode(void); /* Type code */
    NDDSUSERDllExport RTIXCdrTypePlugin *myType_get_type_plugin_info(void);
    NDDSUSERDllExport RTIXCdrSampleAccessInfo *myType_get_sample_access_info(void);
    #endif

    #define REDA_SEQUENCE_USER_API
    #define T myType
    #define TSeq myTypeSeq
    #define REDA_SEQUENCE_EXCLUDE_C_METHODS
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>
    #define REDA_SEQUENCE_USER_API
    #define T myType
    #define TSeq myTypeSeq
    #define REDA_SEQUENCE_EXCLUDE_STRUCT
    #define REDA_SEQUENCE_USER_CPP
    #include <reda/reda_sequence_decl.h>

    NDDSUSERDllExport extern myType*
    myType_create();

    NDDSUSERDllExport extern void
    myType_delete(myType* sample);

    NDDSUSERDllExport
    RTIBool myType_initialize(
        myType* self);

    NDDSUSERDllExport
    RTIBool myType_initialize_ex(
        myType* self,RTIBool allocatePointers,RTIBool allocateMemory);

    NDDSUSERDllExport
    RTIBool myType_initialize_w_params(
        myType* self,
        const struct DDS_TypeAllocationParams_t * allocParams);  

    NDDSUSERDllExport
    RTIBool myType_finalize(
        myType* self);

    NDDSUSERDllExport
    RTIBool myType_finalize_w_return(
        myType* self);

    NDDSUSERDllExport
    void myType_finalize_ex(
        myType* self,RTIBool deletePointers);

    NDDSUSERDllExport
    void myType_finalize_w_params(
        myType* self,
        const struct DDS_TypeDeallocationParams_t * deallocParams);

    NDDSUSERDllExport
    void myType_finalize_optional_members(
        myType* self, RTIBool deletePointers);  

    NDDSUSERDllExport
    RTIBool myType_copy(
        myType* dst,
        const myType* src);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
    /* If the code is building on Windows, stop exporting symbols.
    */
    #undef NDDSUSERDllExport
    #define NDDSUSERDllExport
    #endif

} /* namespace myModule  */

#ifndef NDDS_STANDALONE_TYPE
#endif

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* quickstart */

