/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from quickstart.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "quickstartSupport.h"

/*** SOURCE_BEGIN ***/
namespace myModule {

    /* =========================================================================== */

    /* Requires */
    #define TTYPENAME   myTypeTYPENAME

    /* 
    myModule::myTypeDataWriter (DDSDataWriter)   
    */

    /* Defines */
    #define TDataWriter myTypeDataWriter
    #define TData       myModule::myType

    #ifdef __cplusplus
    #include "dds_cpp/dds_cpp_tdatawriter_gen.hxx"
    #endif

    #undef TDataWriter
    #undef TData

    /* =========================================================================== */
    /* 
    myModule::myTypeDataReader (DDSDataReader)   
    */

    /* Defines */
    #define TDataReader myTypeDataReader
    #define TDataSeq    myTypeSeq
    #define TData       myModule::myType
    #ifdef __cplusplus
    #include "dds_cpp/dds_cpp_tdatareader_gen.hxx"
    #endif
    #undef TDataReader
    #undef TDataSeq
    #undef TData

    /* =========================================================================== */
    /* 
    myModule::myTypeTypeSupport

    */

    #define TTypeSupport myTypeTypeSupport
    #define TData        myModule::myType

    #ifdef __cplusplus
    #include "dds_cpp/dds_cpp_ttypesupport_gen.hxx"
    #endif

    #undef TTypeSupport
    #undef TData

    #undef TTYPENAME

} /* namespace myModule  */

