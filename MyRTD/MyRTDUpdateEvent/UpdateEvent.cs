using System;
using System.Runtime.InteropServices;

namespace MyRTD
{
    /// <summary>
    /// This class is useful when testing RTD servers
    /// from Excel VBA.
    /// 
    /// When Excel calls the RTD ServerStart() method,
    /// it passes a callback through which the RTD can
    /// notify Excel that fresh real-time data is ready
    /// -- a tap on the shoulder of Excel, so to speak.
    /// When Excel is ready, it will ask the RTD server
    /// for the data by calling the RTD's RefreshData()
    /// method.
    /// </summary>
    [Guid("7C32E1F7-003C-46fd-A8DF-1E1650909AF9"),
    ProgId("MyRTD.UpdateEvent"),
    ComVisible(true)]
    public class UpdateEvent : IRTDUpdateEvent
    {
        public long Count { get; set; }
        public int HeartbeatInterval { get; set; }

        public UpdateEvent()
        {
            // Do not call the RTD Heartbeat()
            // method.
            HeartbeatInterval = -1;
        }

        public void Disconnect()
        {
            // Do nothing.
        }

        public void UpdateNotify()
        {
            Count++;
        }
    }
}
