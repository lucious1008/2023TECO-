Imports MySql.Data.MySqlClient

Public Class DeleteAccountModalForm
    Private dbConn As DbConnectionClass
    Private currentUser As String

    Public Sub New(currentUser As String)
        InitializeComponent()
        dbConn = DbConnectionClass.GetInstance("127.0.0.1", 3306, "chat", "teco", "teco1234!")
        Me.currentUser = currentUser
    End Sub


    Private Sub UserDelBtn_Click(sender As Object, e As EventArgs) Handles UserDelBtn.Click
        Dim result As DialogResult = MessageBox.Show("정말 회원탈퇴하시겠습니까?", "회원탈퇴", MessageBoxButtons.YesNo)
        If result = DialogResult.Yes Then
            Dim userId As String = currentUser

            If DeleteUser(userId) Then
                MessageBox.Show("회원탈퇴에 성공하였습니다.")

                Dim mainForm As New mainForm()
                mainForm.Show()
                Me.Close()
            Else
                MessageBox.Show("회원탈퇴에 실패하였습니다.")
            End If
        End If
    End Sub

    Private Function DeleteUser(userId As String) As Boolean
        Dim query As String = "DELETE FROM Users WHERE UserId = @UserId;"
        Try
            Dim command As New MySqlCommand(query, dbConn.GetConnection())
            command.Parameters.AddWithValue("@UserId", userId)

            Dim rowsAffected As Integer = command.ExecuteNonQuery()
            If rowsAffected > 0 Then
                Return True
            Else
                Return False
            End If
        Catch ex As Exception
            MessageBox.Show("회원탈퇴에 실패하였습니다.: " & ex.Message)
        End Try

        Return False
    End Function

    Private Sub closeBtn_Click(sender As Object, e As EventArgs) Handles closeBtn.Click
        Close()
    End Sub
End Class
