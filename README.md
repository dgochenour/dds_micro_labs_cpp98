Lab 1. Out Of The Box

  - Create an IDL file, then generate code
    - $ $RTIMEHOME/rtiddsgen/scripts/rtiddsgen -micro -language C++ -namespace -create typefiles -create examplefiles -create makefiles
  - In the publisher code, give the sample some values, just so they are not empty
  - Build the example code
    - $ $RTIMEHOME/resource/scripts/rtime-make --config Release --build --name x64Darwin17clang9.0 --target Darwin --source-dir . -G "Unix Makefiles" --delete

Lab 2. Deadline QoS

  - Adjust the DR QoS to add a .5s deadline (don't change DW yet)
  - Discuss why this does not work (QoS mismatch)
  - Fix the DW QoS and rerun, showing that data now flows
  - Note that we are actually not sending within the deadline period... add listener

Lab 3. Reporting A QoS Mismatch in the publisher

  - In the publisher code, add a listener to report on Offered QoS incompatability
  - Set the DW deadline period to be 1.5s to cause a QoS mismatch
    - look up DDS_QosPolicyId_t in the docs and discuss

Lab 4. Load user type into Admin Console

  - set DR and DW deadline periods to 1.5s to eliminate match errors
  - create XML type representation and load into Admin Console
    - $RTIMEHOME/rtiddsgen/scripts/rtiddsgen -convertToXml ./quickstart.idl
  - open the tool and note how all DWs are writing to the same instance
    - but it doesn't work if you aren't using namespaces! (change the type name in quickstartApplication.c)
    - also: increase resource limiations in the same file

Lab 5. Switch to a keyed type, and define topic name in IDL

  - modify the IDL to add //@key to the "id" member
  - add a constant for the topic name
  - call rtiddsgen again to impose the change (remember: "update", not "create")
    - $RTIMEHOME/rtiddsgen/scripts/rtiddsgen -micro -language C++ -namespace -update typefiles ./quickstart.idl
  - modify quickstartApplication.cxx to use this constant
  - don't forget to also update the XML type file

Lab 6. Ownership

  - use admin console to view that different instances are being recognized
  - add exclusive ownership and ownership (different students use different
    strengths. Keyed "id" value should be set to the same )

Lab 7. Waitsets

  - remove or comment out the exclusive ownership code in the pub and sub
  - modify the subscriber code to use a waitset to be notified of data
  - "recycle" the listener callback and call it when the WaitSet returns with
    data.
  - don't forget to remove the on_data_available listener code


BONUS LABS

Lab - FlatData

  - create a fresh user project using the flatdata idl
    - $RTIMEHOME/rtiddsgen/scripts/rtiddsgen -micro -language C++ -create typefiles -create examplefiles -create makefiles ./quickstart.idl 
    - on the publisher, modify the writer code to get offsets and set sample values
    - on the subscriber, modify the DR listener to get offsets and print a couple sample values
    
Lab - ZeroCopy

  - create a fresh user project using Image.idl
    - $RTIMEHOME/rtiddsgen/scripts/rtiddsgen -micro -language C++ -create typefiles -create examplefiles -create makefiles ./Image.idl
  - correct the errant double loan in the publisher code (this is MICRO-2079)
  - review the example as generated, pointing out the parts where SHMEM is set up
  - add the FlatData code (this can be "recycled" from the previous lab) to the publisher and subscribercd

Lab - DPSE Discovery

  - create a fresh user project using quickstart.idl
    - $RTIMEHOME/rtiddsgen/scripts/rtiddsgen -micro -language C++ -namespace -create typefiles -create examplefiles -create makefiles ./quickstart.idl
  - update the quickstartApplication.cxx file, replacing dpde entities and variables with dpse
  - update the publisher and subscriber files, discussing the need for the additions
    - don't forget to manually set RTPS object IDs!






