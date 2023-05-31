Imports MySql.Data.MySqlClient

Public Class JoinForm
    Private dbConn As DbConnectionClass

    Public Sub New()
        InitializeComponent()
        dbConn = New DbConnectionClass("127.0.0.1", 3306, "chat", "teco", "teco1234!")
    End Sub

    Private Sub JoinForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        If Not dbConn.OpenConnection() Then
            MessageBox.Show("DBに接続できません。")
        End If
    End Sub

    Private Sub JoinForm_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        dbConn.CloseConnection()
    End Sub

    Private Sub IdConfirmBtn_Click(sender As Object, e As EventArgs) Handles IdConfirmBtn.Click
        Dim userId As String = JoinIdInput.Text.Trim()

        If String.IsNullOrEmpty(userId) Then
            MessageBox.Show("IDを入力してください。")
            Return
        End If

        If CheckIdDuplicate(userId) Then
            MessageBox.Show("使用できるIDです。")
        Else
            MessageBox.Show("이미 사용 중인 아이디입니다.")
        End If
    End Sub

    Private Sub NickConfirmBtn_Click(sender As Object, e As EventArgs) Handles NickConfirmBtn.Click
        Dim nickname As String = JoinNickInput.Text.Trim()

        If String.IsNullOrEmpty(nickname) Then
            MessageBox.Show("ニックネームを入力ください。")
            Return
        End If

        If CheckNicknameDuplicate(nickname) Then
            MessageBox.Show("사용 가능한 닉네임입니다.")
        Else
            MessageBox.Show("이미 사용 중인 닉네임입니다.")
        End If
    End Sub

    Private Sub JoinConfirmBtn_Click(sender As Object, e As EventArgs) Handles JoinConfirmBtn.Click
        Dim userId As String = JoinIdInput.Text.Trim()
        Dim password As String = JoinPwInput.Text
        Dim nickname As String = JoinNickInput.Text.Trim()

        If String.IsNullOrEmpty(userId) OrElse String.IsNullOrEmpty(password) OrElse String.IsNullOrEmpty(nickname) Then
            MessageBox.Show("입력되지 않은 항목이 있습니다.")
            Return
        End If

        Dim newUser As New Users()
        newUser.UserId = userId
        newUser.Password = password
        newUser.Nickname = nickname
        newUser.Role = "User"

        If RegisterUser(newUser) Then
            MessageBox.Show("사용자 등록을 완료하였습니다.")

            Dim mainForm As New mainForm()
            mainForm.Show()
            Me.Close()
        Else
            MessageBox.Show("사용자 등록에 실패하였습니다.")
        End If
    End Sub

    Private Function RegisterUser(user As Users) As Boolean
        If Not CheckIdDuplicate(user.UserId) Then
            MessageBox.Show("이미 사용 중인 아이디입니다.")
            Return False
        End If

        If Not ValidCheckPw(user.Password) Then
            MessageBox.Show("패스워드는 8~14자리의 영대문자 또는 숫자로 입력해 주세요.")
            Return False
        End If

        If Not CheckNicknameDuplicate(user.Nickname) Then
            MessageBox.Show("이미 사용 중인 닉네임입니다.")
            Return False
        End If
        Dim query As String = "INSERT INTO Users (UserId, Password, Nickname, Role) VALUES (@UserId, @Password, @Nickname, @Role);"
        Try
            Dim command As New MySqlCommand(query, dbConn.GetConnection())
            command.Parameters.AddWithValue("@UserId", user.UserId)
            command.Parameters.AddWithValue("@Password", user.Password)
            command.Parameters.AddWithValue("@Nickname", user.Nickname)
            command.Parameters.AddWithValue("@Role", "User")

            Dim rowsAffected As Integer = command.ExecuteNonQuery()
            If rowsAffected > 0 Then
                Return True
            End If
        Catch ex As Exception
            MessageBox.Show("사용자 등록에 실패하였습니다.: " & ex.Message)
        End Try

        Return False

    End Function

    Private Function CheckIdDuplicate(userId As String) As Boolean
        Dim query As String = "SELECT COUNT(*) FROM Users WHERE UserId = @UserId;"
        Try
            Dim command As New MySqlCommand(query, dbConn.GetConnection())
            command.Parameters.AddWithValue("@UserId", userId)

            Dim count As Integer = CInt(command.ExecuteScalar())
            If count > 0 Then
                Return False
            End If
        Catch ex As Exception
            MessageBox.Show("ID 중복 체크 중에 오류가 발생하였습니다.: " & ex.Message)
        End Try

        Return True
    End Function
    Private Function ValidCheckPw(password As String) As Boolean
        If password.Length < 8 OrElse password.Length > 14 Then
            MessageBox.Show("비밀번호는 8~14자리로 입력해주세요.")
            Return False
        End If

        Dim hasLetter As Boolean = False
        Dim hasNumber As Boolean = False

        For Each c As Char In password
            If Char.IsLetter(c) Then
                hasLetter = True
            ElseIf Char.IsNumber(c) Then
                hasNumber = True
            End If
        Next

        If Not hasLetter OrElse Not hasNumber Then
            MessageBox.Show("비밀번호는 영문자와 숫자의 조합으로 입력해주세요.")
            Return False
        End If

        Return True

    End Function

    Private Function CheckNicknameDuplicate(nickname As String) As Boolean
        Dim query As String = "SELECT COUNT(*) FROM Users WHERE Nickname = @Nickname;"
        Try
            Dim command As New MySqlCommand(query, dbConn.GetConnection())
            command.Parameters.AddWithValue("@Nickname", nickname)

            Dim count As Integer = CInt(command.ExecuteScalar())
            If count > 0 Then
                Return False
            End If
        Catch ex As Exception
            MessageBox.Show("닉네임 중복 체크 중에 오류가 발생하였습니다.: " & ex.Message)
        End Try

        Return True
    End Function

End Class