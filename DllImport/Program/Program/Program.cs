using System;
using System.IO;
using TestDLL;

namespace Program
{
    class Program
    {
        static void Main(string[] args)
        {
            Test dll = new Test();

            Console.WriteLine(dll.Win32OrWin64());

            // Debug: keep the terminal window open.
            Console.ReadLine();
        }
    }
}
