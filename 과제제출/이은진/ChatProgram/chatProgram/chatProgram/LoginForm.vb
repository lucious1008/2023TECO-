Imports MySql.Data.MySqlClient

Public Class LoginForm

    Private connStr As String = "server=localhost;Database=chat;id=teco;password=teco;"
    Private conn As MySqlConnection

    Private Sub InitializeDBObject()
        conn = New MySqlConnection(connStr)
    End Sub

    Private Sub CheckDBConnection()
        Try
            conn.Open()
            If conn.State = ConnectionState.Open Then
                MessageBox.Show("DBに接続完了しました。")
            Else
                MessageBox.Show("DBに接続を失敗しました。")
            End If
        Catch ex As Exception
            MessageBox.Show("DBに接続を失敗しました :" & ex.Message)
        Finally
            conn.Close()
        End Try
    End Sub

    Private Sub LoginForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub LoginConfirmBtn_Click(sender As Object, e As EventArgs) Handles LoginConfirmBtn.Click

    End Sub
End Class