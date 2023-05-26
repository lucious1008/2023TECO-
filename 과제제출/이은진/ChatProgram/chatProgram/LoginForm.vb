Imports System.Net.Http
Imports MySql.Data.MySqlClient

Public Class LoginForm
    Private dbConn As DbConnectionClass

    Public Sub New()
        InitializeComponent()
        dbConn = New DbConnectionClass("127.0.0.1", 3306, "chat", "teco", "teco1234!")
    End Sub

    Private Sub LoginForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        If Not dbConn.OpenConnection() Then
            MessageBox.Show("데이터베이스 연결을 열 수 없습니다.")
        End If
    End Sub

    Private Sub LoginForm_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        dbConn.CloseConnection()
    End Sub

    Private Sub LoginConfirmBtn_Click(sender As Object, e As EventArgs) Handles LoginConfirmBtn.Click
        Dim userId As String = LoginIdInput.Text
        Dim password As String = LoginPwInput.Text

        LoginPwInput.PasswordChar = "*"c

        If AuthUser(userId, password) Then
            MessageBox.Show("인증되었습니다.")

            ' 세션 로그인 정보 저장 및 처리
            'HttpContext.Current.Session("UserId") = userId ' 사용자 ID를 세션에 저장
            'HttpContext.Current.Session("LoggedIn") = True ' 로그인 상태 플래그를 세션에 저장
            '' 필요한 경우 추가적인 사용자 정보를 세션에 저장
            '' HttpContext.Current.Session("UserName") = userName
            ' ...

            ' ChattingForm으로 화면 전환
            Dim chattingForm As New ChattingForm()
            chattingForm.Show()
            Me.Hide()
        Else
            MessageBox.Show("ID 또는 PW가 잘못되었습니다.")
        End If
    End Sub

    Private Function AuthUser(userId As String, password As String) As Boolean
        Dim query As String = $"SELECT COUNT(*) FROM Users WHERE UserId = '{userId}' AND Password = '{password}';"
        Try
            Dim command As New MySqlCommand(query, dbConn.GetConnection())
            Dim count As Integer = CInt(command.ExecuteScalar())
            If count > 0 Then
                Return True
            End If
        Catch ex As Exception
            MessageBox.Show("사용자 인증 중에 오류가 발생하였습니다.: " & ex.Message)
        End Try

        Return False
    End Function

End Class