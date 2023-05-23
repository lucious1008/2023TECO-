Imports MySql.Data.MySqlClient

Public Class DBConnector
    Private connStr As String = "server=localhost;port=3360;database=chat;user=teco;password=teco1234!;"
    Private conn As MySqlConnection

    Public Sub New()
        InitializeDBObject()
    End Sub

    Private Sub InitializeDBObject()
        conn = New MySqlConnection(connStr)
    End Sub

    Public Function CheckDBConnection() As Boolean
        Try
            conn.Open()
            If conn.State = ConnectionState.Open Then
                MessageBox.Show("DBに接続さてました。")
                Return True
            Else
                MessageBox.Show("DBに接続を失敗しました。")
                Return False
            End If
        Catch ex As Exception
            MessageBox.Show("DBに接続を失敗しました :" & ex.Message)
            Return False
        Finally
            conn.Close()
        End Try
    End Function
End Class
