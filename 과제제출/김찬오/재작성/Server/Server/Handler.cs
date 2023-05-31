using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Sockets;
using System.IO;
using System.Threading;
namespace Server
{
    public class Handler
    {
        private Socket client;
        public Handler(Socket client)
        {
            this.client = client;
            Thread t = new Thread(new ThreadStart(ClientHandling));
            t.Start();
        }
        private void ClientHandling()
        {
            Byte[] recvByte = new Byte[1024];
            string recvStr;
            try
            {
                BroadCast(client.RemoteEndPoint.ToString() + " 입장");
                while (true)
                {
                    int recvCnt = client.Receive(recvByte);
                    recvStr = Encoding.Default.GetString(recvByte,0, recvCnt);
                    Console.WriteLine("수신 데이터 : " + recvStr);
                    if (recvStr == "exit")
                        break; 
                    BroadCast(recvStr);
               
            }
            catch 
            {
                Console.WriteLine("연결이 끊어졌습니다.");
            }
            finally
            {
                ServerMain.socketList.Remove(client);
                Console.WriteLine(client.RemoteEndPoint.ToString() + " 접속종료.");
                BroadCast(client.RemoteEndPoint.ToString() + " 접속종료.");
                client.Close();
            }
        }
            private void BroadCast(string msg)
            
        {
            Byte[] sendByte = Encoding.Default.GetBytes(msg);
            foreach (Socket s in ServerMain.socketList)
            {
                s.Send(sendByte);
            }
        }
    }
}
