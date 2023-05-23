Imports MySql.Data.MySqlClient

Public Class JoinForm

    Private connStr As String = "server=localhost;port=3360;database=chat;id=teco;password=teco1234!;"
    Private conn As MySqlConnection

    Private Sub InitializeDBObject()
        conn = New MySqlConnection(connStr)
    End Sub

    Private Sub CheckDBConnection()
        Try
            conn.Open()
            If conn.State = ConnectionState.Open Then
                MessageBox.Show("DBに接続を完了しました。")
            Else
                MessageBox.Show("DBに接続を失敗しました。")
            End If
        Catch ex As Exception
            MessageBox.Show("DBに接続を失敗しました。" & ex.Message)
        Finally
            conn.Close()
        End Try
    End Sub

    Private Function RegisterUser(user As Users) As Boolean
        Dim query As String = "INSERT INTO Users (UserId, Password, Nickname) VALUES (@UserId, @Password, @Nickname);"
        Dim result As Boolean = False
        Try
            conn.Open()
            Dim command As New MySqlCommand(query, conn)
            command.Parameters.AddWithValue("@UserId", user.UserId)
            command.Parameters.AddWithValue("@Password", user.Password)
            command.Parameters.AddWithValue("@Nickname", user.Nickname)

            Dim rowsAffected As Integer = command.ExecuteNonQuery()
            If rowsAffected > 0 Then
                result = True
            End If
        Catch ex As Exception
            MessageBox.Show("ユーザー登録に失敗しました。: " & ex.Message)
        Finally
            conn.Close()
        End Try

        Return result

    End Function

    Private Sub JoinConfirmBtn_Click(sender As Object, e As EventArgs) Handles JoinConfirmBtn.Click
        ' JoinConfirmBtn 버튼 클릭 이벤트 핸들러

        ' 유저 정보 생성
        Dim newUser As New Users()
        newUser.UserId = JoinIdInput.Text
        newUser.Password = JoinPwInput.Text
        newUser.Nickname = JoinNickInput.Text

        ' 사용자 등록
        Dim isSuccess As Boolean = RegisterUser(newUser)
        If isSuccess Then
            MessageBox.Show("ユーザー登録を完了しました。")
        End If

    End Sub

    Private Sub JoinForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ' 폼 로드 이벤트 핸들러
        InitializeDBObject()
        CheckDBConnection()
    End Sub

End Class
