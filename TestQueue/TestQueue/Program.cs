using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.ServiceBus.Messaging;

namespace TestQueue
{
    class Program
    {
        
        static string ConnectionString = "Endpoint=sb://testdmbus.servicebus.windows.net/;SharedAccessKeyName=RootManageSharedAccessKey;SharedAccessKey=QFnn7wxNdoZBExkXLq9CJJf6dXMg/Uqjd/IlRin6060=";
static string QueuePath = "testdmqueue";
        static void Main(string[] args)
        {
            //Service Bus Queue Sender
            var queueClient = QueueClient.CreateFromConnectionString(ConnectionString,
            QueuePath);
            for (int i = 0; i < 10; i++)
            {
                var message = new BrokeredMessage("Sender's Message ==> " + i);
                // message.SessionId = “test”;
                queueClient.Send(message);
                Console.Write("\nSent Message : = " + i);
            }
            Console.WriteLine("Press Enter to Exit...");
            Console.ReadLine();
            queueClient.Close();
        }
    }
}
