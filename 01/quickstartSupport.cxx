/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from quickstart.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "quickstartSupport.h"

/*** SOURCE_BEGIN ***/

/* =========================================================================== */

/* Requires */
#define TTYPENAME   myModule_myTypeTYPENAME

/* 
myModule_myTypeDataWriter (DDSDataWriter)   
*/

/* Defines */
#define TDataWriter myModule_myTypeDataWriter
#define TData       myModule_myType

#ifdef __cplusplus
#include "dds_cpp/dds_cpp_tdatawriter_gen.hxx"
#endif

#undef TDataWriter
#undef TData

/* =========================================================================== */
/* 
myModule_myTypeDataReader (DDSDataReader)   
*/

/* Defines */
#define TDataReader myModule_myTypeDataReader
#define TDataSeq    myModule_myTypeSeq
#define TData       myModule_myType
#ifdef __cplusplus
#include "dds_cpp/dds_cpp_tdatareader_gen.hxx"
#endif
#undef TDataReader
#undef TDataSeq
#undef TData

/* =========================================================================== */
/* 
myModule_myTypeTypeSupport

*/

#define TTypeSupport myModule_myTypeTypeSupport
#define TData        myModule_myType

#ifdef __cplusplus
#include "dds_cpp/dds_cpp_ttypesupport_gen.hxx"
#endif

#undef TTypeSupport
#undef TData

#undef TTYPENAME

