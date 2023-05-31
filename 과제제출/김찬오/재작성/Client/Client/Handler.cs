using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Sockets;
using System.Threading;
namespace Client
{
    public class Handler
    {
        private Client c;
        private Socket client;
        public Handler(Client c, Socket client)
        {
            this.c = c;
            this.client = client;
            Thread t = new Thread(new ThreadStart(Handling));
            t.Start();
        }
        private void Handling()
        {
            Byte[] recvByte = new Byte[1024];
            string recvStr;
            try
            {
                while (true)
                {
                    int recvCnt = client.Receive(recvByte);
                    recvStr = Encoding.Default.GetString(recvByte, 0, recvCnt);
                    c.OutputText(recvStr);
                }
            }
            catch
            {
                c.OutputText("연결이 끊어졌습니다.");
            }
            finally
            {
                c.OutputText("접속 종료됨.");
                client.Close();
            }
        }
    }
}
