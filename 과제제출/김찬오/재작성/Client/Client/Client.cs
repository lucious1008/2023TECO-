using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net.Sockets;
using System.Net;
namespace Client
{
    public partial class Client : Form
    {
        private Socket client;
        private string IP = "localhost";
        private int PORT = 9768;
        public Client()
        {
            InitializeComponent();
            Connect();
        }

        private void Connect()
        {
            try
            {
                client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                client.Connect(IP, PORT);
                if (client.Connected)
                {
                    OutputText("접속 성공했습니다.");
                    Text = client.LocalEndPoint.ToString();
                    new Handler(this, client);
                }
            }
            catch
            {
                OutputText("서버가 열려있지 않습니다.");
            }
        }

        private void inputTb_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == '\r')
            {
                SendMessage();
            }
        }

        private void SendMessage()
        {
            if (client.Connected)
            {
                Byte[] sendByte = Encoding.Default.GetBytes(client.LocalEndPoint.ToString() + " : " + 
                                                            inputTb.Text);
                client.Send(sendByte);
                inputTb.Text = "";
                inputTb.Select();
            }
        }

        private void sendBt_Click(object sender, EventArgs e)
        {
            SendMessage();
        }

        public void OutputText(string msg)
        {
            outputLb.Items.Add(msg);
            outputLb.SelectedIndex = outputLb.Items.Count-1;
        }

        private void Client_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (client.Connected)
            {
                Byte[] sendByte = Encoding.Default.GetBytes("exit");
                client.Send(sendByte);
                client.Close();
            }
        }
    }
}
