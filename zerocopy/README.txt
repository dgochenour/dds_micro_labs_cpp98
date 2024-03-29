
=====================
C++ Image w/ Dynamic Discovery Example
=====================

An example publication and subscription pair to send and receive simple strings.

An example publication and subscription pair to send and receive simple strings.
Discovery of endpoints is done with the dynamic-endpoint discovery.

Purpose
=======

This example shows how to perform basic publish-subscribe communication.

This example differs from the HelloWorld example in that endpoint discovery is 
done dynamically: state of remote endpoints are propagated automatically by 
built-in discovery endpoints, and the user does not need to manually configure 
remote endpoint state.

For convenience, complete source code, a sample makefile for Linux and VxWorks, 
and a sample project for Windows has been provided.


Source Overview
===============

A simple "Image" type, containing a message string, is defined in 
Image.idl.

For the type to be useable by Connext Micro, type-support files must be 
generated that implement a type-plugin interface.  The example Makefile 
will generate these support files, by invoking rtiddsgen.  Note that rtiddsgen
can be invoked manually, with an example command like this:

    ${RTIMEHOME}/rtiddsgen/scripts/rtiddsgen -micro -language C++ Image.idl

The generated source files are Image.cxx, ImageSupport.cxx, and 
ImagePlugin.cxx. Associated header files are also generated.
 
The DataWriter and DataReader of the type are managed in Image_publisher.cxx
and Image_subscriber.cxx, respectively. The DomainParticipant of each is 
managed in ImageApplication.cxx
  


Example Files Overview
======================

ImageApplication.cxx:
This file contains the logic for creating an application.  This includes steps 
for configuring discovery and creating a DomainParticipant.  This file also 
includes code for registering a type with the DomainParticipant.

Image_publisher.cxx:
This file contains the logic for creating a Publisher and a DataWriter, and 
sending data.  

Image_subscriber.cxx:
This file contains the logic for creating a Subscriber and a DataReader, a 
DataReaderListener, and listening for data.

ImagePlugin.cxx:
This file creates the plugin for the Image data type.  This file contains 
the code for serializing and deserializing the Image type, creating, 
copying, printing and deleting the Image type, determining the size of the 
serialized type, and handling hashing a key, and creating the plug-in.

ImageSupport.cxx
This file defines the Image type and its typed DataWriter, DataReader, and 
Sequence.

Image.cxx
This file contains the APIs for managing the Image type.


How to Compile and Run
======================


--------------------
Compiling with CMake
--------------------
Before compiling, set environment variable RTIMEHOME to the Connext Micro 
installation directory. 

The RTI Connext DDS Micro source bundle includes a bash (Unix) and BAT (Windows)
script to simplify the invocation of CMake. These scripts is a convenient way 
to invoke CMake with the correct options. E.g.

Linux
-----
cd "<ImageApplication directory>"
rtime-make --config <Debug|Release> --build --name x64Linux3gcc4.8.2 --target Linux --source-dir . -G "Unix Makefiles" --delete

Windows
-------
cd "<ImageApplication directory>"
rtime-make.bat --config <Debug|Release> --build --name i86Win32VS2010 --target Windows --source-dir . -G "Visual Studio 10 2010" --delete

Darwin
------
cd "<ImageApplication directory>"
rtime-make --config <Debug|Release> --build --name x64Darwin17.3.0Clang9.0.0 --target Darwin --source-dir . -G "Unix Makefiles" --delete

The executable can be found on directory "objs"



It is also possible to compile using CMake, e.g. in case the RTI Connext DDS 
Micro source bundle is not installed.  


Linux
-----
cmake [-DCMAKE_BUILD_TYPE=<Debug|Release>] -G "Unix Makefiles" -B./<your build directory> -H. -DRTIME_TARGET_NAME=x64Linux3gcc4.8.2 -DPLATFORM_LIBS="dl;nsl;m;pthread;rt"
cmake --build ./<your build directory> [--config <Debug|Release>]

Windows
-------
cmake [-DCMAKE_BUILD_TYPE=<Debug|Release>] -G "Visual Studio 10 2010" -B./<your build directory> -H. -DRTIME_TARGET_NAME=i86Win32VS2010 -DPLATFORM_LIBS="netapi32.lib;advapi32.lib;user32.lib;winmm.lib;WS2_32.lib;"
cmake --build ./<your build directory> [--config <Debug|Release>]

Darwin
------
cmake [-DCMAKE_BUILD_TYPE=<Debug|Release>] -G "Unix Makefiles" -B./<your build directory> -H. -DRTIME_TARGET_NAME=x64Darwin17.3.0Clang9.0.0 -DPLATFORM_LIBS="dl;m;pthread"
cmake --build ./<your build directory> [--config <Debug|Release>]

The executable can be found on ./objs

------------------------------------------------------
Running Image_publisher and Image_subscriber
------------------------------------------------------

E.g. in case the Image has been compiled for Linux i86Linux2.6gcc4.4.5 run the subscriber by typing:

objs/i86Linux2.6gcc4.4.5/Image_subscriber -domain <Domain_ID> -peer <address> -sleep <sleep_time> -count <seconds_to_run>

and run the publisher by typing:

objs/i86Linux2.6gcc4.4.5/Image_publisher -domain <Domain_ID> -peer <address> -sleep <sleep_time> -count <seconds_to_run>
