using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Sockets;
using System.Net;
using System.Collections;
namespace Server
{
    public class ServerMain
    {
        private Socket server;
        public static ArrayList socketList = new ArrayList();
        static void Main(string[] args)
        {
            new ServerMain();
        }
        public ServerMain()
        {
            Create();
        }
        private void Create()
        {
            try
            {
                IPEndPoint ipep = new IPEndPoint(IPAddress.Any, 9768);
                server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                server.Bind(ipep);
                server.Listen(20);
                Console.WriteLine("서버가동 시작.");
                Accept();
            }
            catch
            {
                Console.WriteLine("포트가 중복됩니다.");
            }
        }
        public void Accept()
        {
            try
            {
                while (true)
                {
                    Socket client = server.Accept();
                    socketList.Add(client);// 배열에 소켓추가
                    Console.WriteLine(client.RemoteEndPoint.ToString() + " 접속함(현재 접속인원 : "+ socketList.Count + ")");
                    new Handler(client); // 서버 쓰레드 시작
                }
            }
            catch
            {
                Console.WriteLine("연결이 끊어졌습니다.");
            }

        }
    }
}
