using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace WindowsFormsApp1
{
    public partial class Form2 : Form
    {
        string strConn = "Server=localhost;Port=3306;Database=mydb;Uid=root;Pwd=Root";
        public Form2()
        {
            InitializeComponent();
        }
        private void button3_Click(object sender, EventArgs e)
        {
            MySqlConnection conn = new MySqlConnection(strConn);
            string insertQuery = "insert into user(id,pw)values('asdfa',1234)";
            try
            {
                conn.Open();
                MySqlCommand command = new MySqlCommand(insertQuery, conn);

                if (command.ExecuteNonQuery() == 1)
                {
                    Console.WriteLine("成功");
                }
                else
                {
                    Console.WriteLine("失敗");
                }
                conn.Close();
                }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //id確認
        }
    }
}
