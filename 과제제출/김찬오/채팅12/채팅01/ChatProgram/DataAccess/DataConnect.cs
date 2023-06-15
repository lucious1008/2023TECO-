using System;
using System.Data.SqlClient;

class Program
{
    static void Main()
    {
        string connectionString = "Data Source=127.0.0.1:3306;Initial Catalog=kco1;User ID=root;Password=cksdh1";

        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            connection.Open();

            // ȸ�� ��� ���
            Console.WriteLine("������:");
            Console.WriteLine("------------");
            string query = "SELECT * FROM kco1";
            SqlCommand command   = new SqlCommand(query, connection);
            SqlDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                int userid = (int)reader["user_id"];
                string name = (string)reader["name"];
                string password = (string)reader["password"];
                string phoneNumber = (string)reader["phone_number"];
                string location = (string)reader["location"];

                Console.WriteLine($"user ID: {userid}, Name: {name}, Password: {password}, Phone Number: {phoneNumber}, Location: {location}");
            }

            reader.Close();

            // �α��� ����
            Console.WriteLine();
            Console.WriteLine("�α���:");
            Console.WriteLine("-------------");
            Console.Write("�����Է�: ");
            string username = Console.ReadLine();
            Console.Write("��й�ȣ: ");
            string password = Console.ReadLine();

            query = "SELECT COUNT(*) FROM kco1 WHERE name = @Username AND password = @Password";
            command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@Username", username);
            command.Parameters.AddWithValue("@Password", password);

            int count = (int)command.ExecuteScalar();

            if (count > 0)
            {
                Console.WriteLine("�α��� ����!");
            }
            else
            {
                Console.WriteLine("Ʋ�������̸�.");
            }
        }
    }
}