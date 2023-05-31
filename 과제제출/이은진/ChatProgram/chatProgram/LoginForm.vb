Imports MySql.Data.MySqlClient

Public Class LoginForm
    Private dbConn As DbConnectionClass
    Private currentUser As String

    Public Sub New()
        InitializeComponent()
        dbConn = DbConnectionClass.GetInstance("127.0.0.1", 3306, "chat", "teco", "teco1234!")
    End Sub

    Private Sub LoginBtn_Click(sender As Object, e As EventArgs) Handles LoginConfirmBtn.Click
        Dim userId As String = LoginIdInput.Text
        Dim password As String = LoginPwInput.Text

        If dbConn.IsConnectionOpen() Then
            If ValidateUser(userId, password) Then
                MessageBox.Show("로그인 성공!")

                Dim loginSession As LoginSession = LoginSession.GetInstance()
                loginSession.SetLoggedInUser(userId)

                Dim chattingForm As New ChattingForm(userId)
                chattingForm.Show()
                Me.Hide()
            Else
                MessageBox.Show("아이디 또는 비밀번호가 잘못되었습니다.")
            End If
        Else
            If dbConn.OpenConnection() Then
                If ValidateUser(userId, password) Then
                    MessageBox.Show("로그인 성공!")

                    Dim loginSession As LoginSession = LoginSession.GetInstance()
                    loginSession.SetLoggedInUser(userId)

                    Dim chattingForm As New ChattingForm(userId)
                    chattingForm.Show()
                    Me.Hide()
                Else
                    MessageBox.Show("아이디 또는 비밀번호가 잘못되었습니다.")
                End If
            Else
                MessageBox.Show("데이터베이스 연결에 실패하였습니다.")
            End If
        End If
    End Sub

    Private Function ValidateUser(userId As String, password As String) As Boolean
        Dim query As String = "SELECT COUNT(*) FROM Users WHERE UserId = @UserId AND Password = @Password;"
        Dim result As Integer = 0

        Try
            Using command As New MySqlCommand(query, dbConn.GetConnection())
                command.Parameters.AddWithValue("@UserId", userId)
                command.Parameters.AddWithValue("@Password", password)

                result = Convert.ToInt32(command.ExecuteScalar())
            End Using
        Catch ex As Exception
            MessageBox.Show("사용자 인증 중에 오류가 발생했습니다.: " & ex.Message)
        End Try

        Return result > 0
    End Function

    Private Sub LoginForm_FormClosing(sender As Object, e As FormClosingEventArgs) Handles Me.FormClosing
        Dim loginSession As LoginSession = LoginSession.GetInstance()
        loginSession.ClearSession()
    End Sub
End Class
