' ProgIDs for COM components.
Const RTDProgID = "MyRTD.RTD"
Const RTDEXEProgID = "MyRTDEXE.RTD"
Const UpdateEventProgID = "MyRTD.UpdateEvent"

'----------------------------------------
' Test both the in-process (DLL) and
' out-of-process (EXE) RTD servers.
'----------------------------------------

    MsgBox "Test in-process (DLL) RTD server."
    Call TestMyRTD(RTDProgID, UpdateEventProgID)

    'MsgBox "Test out-of-process (EXE) RTD server."
    'Call TestMyRTD(RTDEXEProgID, UpdateEventProgID)

'----------------------------------------
' Test RTD server by emulating the calls
' that Excel makes to the IRTDServer
' interface.
'----------------------------------------
Private Sub TestMyRTD(rtdID,eventID)

On Error Resume Next
Err.Clear

    ' Real-time data (RTD) object
    Dim rtd
    Set rtd = CreateObject(rtdID)   
    If Err.Number <> 0 Then
        MsgBox Err.Description
        Err.Clear
    Else
        MsgBox "RTD object (" _
               & rtdID _
               & ") created successfully." _
               & "TypeName(rtd) = " _
               & TypeName(rtd)
    End If

    ' Callback object. This is how
    ' the RTD would notify Excel of
    ' new data updates.
    Dim callback
    Set callback = CreateObject(UpdateEventProgID)
    If Err.Number <> 0 Then
        MsgBox Err.Description
        Err.Clear
    Else
        MsgBox "Callback object (" _
               & eventID _
               & ") created successfully. " _
               & "TypeName(callback) = " _
               & TypeName(callback)
    End If

    ' Start the RTD server, passing in
    ' the callback object.
    Dim status
    status = rtd.ServerStart(callback)
    If Err.Number <> 0 Then
        MsgBox Err.Description
        Err.Clear
    Else
        MsgBox "RTD server started by calling "  & _
               "status = ServerStart(callback). " & _
               "status = " & status
    End If
 
    ' Code to get data from the RTD goes here.
 
    ' Tidy up.
    rtd.ServerTerminate

End Sub
