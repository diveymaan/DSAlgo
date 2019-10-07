using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.ServiceBus.Messaging;

namespace TestReceiver
{
    class Program
    {
        static string ConnectionString = "Endpoint=sb://testdmbus.servicebus.windows.net/;SharedAccessKeyName=RootManageSharedAccessKey;SharedAccessKey=QFnn7wxNdoZBExkXLq9CJJf6dXMg/Uqjd/IlRin6060=";
        static string QueuePath = "testdmqueue";
        static void Main(string[] args)
        { //Service Bus Queue Receiver 
            var queueClient = QueueClient.CreateFromConnectionString(ConnectionString, QueuePath);
            queueClient.OnMessage(msg => ProcessMessage(msg));
            Console.WriteLine("Press Enter to Exit..."); Console.ReadLine();
            queueClient.Close();
        }
        private static void ProcessMessage(BrokeredMessage msg)
        {
            var text = msg.GetBody<string>();
            Console.WriteLine("\nReceived Messages : " + text);
        }
    }
}
