using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace TestApp1
{
    class Program
    {
        [DllImport("kernel32.dll")]
        static extern IntPtr GetConsoleWindow();

        [DllImport("user32.dll")]
        static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);

        const int SW_HIDE = 0;
        const int SW_SHOW = 5;
        static void Main(string[] args)
        {
            string temp = "This is test!!";
            Console.WriteLine("This is test!!");
            var handle = GetConsoleWindow();

            // Hide
            ShowWindow(handle, SW_HIDE);
            for (; ; )
            { }

           

            // Show
           // ShowWindow(handle, SW_SHOW);
        }
    }
}
