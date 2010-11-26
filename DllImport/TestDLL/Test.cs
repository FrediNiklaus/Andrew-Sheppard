using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Reflection;

namespace TestDLL
{
    public class Test
    {
        // The Windows loader will automatically load
        // the 32-bit or 64-bit version of kernel32.dll
        // on 64-bit Windows. On 32-bit Windows it will
        // load the 32-bit version of kernel32.dll from
        // C:\Windows\System32, and on 64-bit Windows
        // it will load the 32-bit version of kernel32.dll
        // from C:\Windows\SysWOW64 and the 64-bit version
        // of kernel32.dll from C:\Windows\System32, as
        // required by the calling process (32 or 64-bits).
        [DllImport("kernel32.dll", CallingConvention = CallingConvention.Winapi)]
        public static extern bool SetDllDirectory([MarshalAs(UnmanagedType.LPStr)]
                                                   String pathName);

        // The 32-bit or 64-bit version of Test.dll will be
        // loaded depending on the "bitness" (32 or 64) of tha
        // process that loads this assembly (DLL). This will
        // be done by adding to the DLL search path the path
        // of the directory holding the 32 or 64-bit version
        // of Test.dll, as required.
        [DllImport("Test.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int WindowsBitness();
        [DllImport("Test.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int ProcessBitness();

        // Update the DLL search path when the first
        // instance of the Test class is created. Do this
        // only once.
        static Test()
        {
            const String DLL32 = "\\DLL32";
            const String DLL64 = "\\DLL64";

            String path = Path.GetDirectoryName(Assembly.GetEntryAssembly().Location);
            String pathDLL32 = path + DLL32;
            String pathDLL64 = path + DLL64;

            Boolean status;

            if (IntPtr.Size == 4)
                status = SetDllDirectory(pathDLL32);
            else
                status = SetDllDirectory(pathDLL64);
        }

        // Bitness of process and bitness of Windows platform
        // running that process.
        public String Win32OrWin64()
        {
            int windowsBits = WindowsBitness();
            int processBits = ProcessBitness();

            return "Running " + processBits.ToString() + "-bit application on " +
                    windowsBits.ToString() + "-bit Windows.";
        }
    }
}
