using System;
using System.Reflection;
using System.Threading;

namespace MyRTD
{
    class Program
    {
        // ProgIDs for COM classes.
        private const String RTDProgID = "MyRTD.RTD";
        private const String RTDUpdateEventProgID = "MyRTD.UpdateEvent";
        private const String RTDEXEProgID = "MyRTDEXE.RTD";
        private const String RTDEXEUpdateEventProgID = "MyRTDEXE.UpdateEvent";

        // Dummy topic.
        private const int topicID = 12345;
        private const String topic = "topic";

        static void Main(string[] args)
        {
            Console.WriteLine("Test in-process (DLL) RTD server.");
            TestMyRTD(RTDProgID,RTDUpdateEventProgID);

            Console.WriteLine("Test out-of-process (EXE) RTD server.");
            TestMyRTD(RTDEXEProgID,RTDEXEUpdateEventProgID);

            Console.WriteLine("Press enter to exit ...");
            Console.ReadLine();
        }

        static void TestMyRTD(String rtdID, String eventID)
        {
            try
            {
                // Create the RTD server.
                Type rtd;
                Object rtdServer = null;
                rtd = Type.GetTypeFromProgID(rtdID);
                rtdServer = Activator.CreateInstance(rtd);
                Console.WriteLine("rtdServer = {0}", rtdServer.ToString());

                // Create a callback event.
                Type update;
                Object updateEvent = null;
                update = Type.GetTypeFromProgID(eventID);
                updateEvent = Activator.CreateInstance(update);
                Console.WriteLine("updateEvent = {0}", updateEvent.ToString());

                // Start the RTD server.
                Object[] param = new Object[1];
                param[0] = updateEvent;
                MethodInfo method = rtd.GetMethod("ServerStart");
                Object ret; // Return value.
                ret = method.Invoke(rtdServer, param);
                Console.WriteLine("ret for 'ServerStart()' = {0}", ret.ToString());

                // Request data from the RTD server.
                Object[] topics = new Object[1];
                topics[0] = topic;
                Boolean newData = true; // Request new data, not cached data.
                param = new Object[3];
                param[0] = topicID;
                param[1] = topics;
                param[2] = newData;
                method = rtd.GetMethod("ConnectData");
                ret = method.Invoke(rtdServer, param);
                Console.WriteLine("ret for 'ConnectData()' = {0}", ret.ToString());

                // Loop and wait for RTD to notify (via callback) that
                // data is available.
                int count = 0;
                do
                {
                    count++;

                    // Check that the RTD server is still alive.
                    Object status;
                    param = null;
                    method = rtd.GetMethod("Heartbeat");
                    status = method.Invoke(rtdServer, param);
                    Console.WriteLine("status for 'Heartbeat()' = {0}", status.ToString());

                    // Get data from the RTD server.
                    int topicCount = 0;
                    param = new Object[1];
                    param[0] = topicCount;
                    method = rtd.GetMethod("RefreshData");
                    Object[,] retval = new Object[2, 1];
                    retval = (Object[,])method.Invoke(rtdServer, param);
                    Console.WriteLine("retval for 'RefreshData()' = {0}", retval[1,0].ToString());

                    // Wait for 2 seconds before getting
                    // more data from the RTD server.
                    Thread.Sleep(2000);

                } while (count < 5); // Loop 5 times.

                // Disconnect from data topic.
                param = new Object[1];
                param[0] = topicID;
                method = rtd.GetMethod("DisconnectData");
                method.Invoke(rtdServer, param);

                // Shutdown the RTD server.
                param = null;
                method = rtd.GetMethod("ServerTerminate");
                method.Invoke(rtdServer, param);
            }
            catch (Exception e)
            {
                Console.WriteLine("Error: {0} ", e.Message);
            }
        }
    }
}
