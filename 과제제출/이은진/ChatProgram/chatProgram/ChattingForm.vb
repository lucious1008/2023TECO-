Imports MySql.Data.MySqlClient

Public Class ChattingForm
    Private dbConn As DbConnectionClass
    Private isLoggedIn As Boolean = True ' 로그인 상태를 나타내는 변수

    Public Sub New()
        InitializeComponent()
        dbConn = New DbConnectionClass("127.0.0.1", 3306, "chat", "teco", "teco1234!")
    End Sub

    Private Sub ChattingForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        If Not dbConn.OpenConnection() Then
            MessageBox.Show("데이터베이스 연결을 열 수 없습니다.")
        End If

        ' 접속 중인 유저 표시
        ShowConnectedUsers()
    End Sub

    Private Sub ChattingForm_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        dbConn.CloseConnection()
    End Sub

    Private Sub ShowConnectedUsers()
        Dim query As String = "SELECT Users.Nickname FROM ConnectedUsers INNER JOIN Users ON ConnectedUsers.UserId = Users.UserId"
        Dim command As New MySqlCommand(query, dbConn.GetConnection())

        Try
            Dim reader As MySqlDataReader = command.ExecuteReader()
            While reader.Read()
                Dim nickname As String = reader.GetString("Nickname")
                ' OnlineUserChk에 유저 추가
                Dim item As New ListViewItem(nickname)
                OnlineUserChk.Items.Add(item)
            End While
            reader.Close()
        Catch ex As Exception
            MessageBox.Show("접속 중인 유저 정보를 가져오는 중에 오류가 발생하였습니다: " & ex.Message)
        End Try
    End Sub

    Private Sub MypageBtn_Click(sender As Object, e As EventArgs) Handles MypageBtn.Click
        If isLoggedIn Then
            Dim mypageForm As New MypageForm()
            mypageForm.ShowDialog()
            Me.Hide()
        End If
    End Sub

    Private Sub LogoutBtn_Click(sender As Object, e As EventArgs) Handles LogoutBtn.Click
        Dim result As DialogResult = MessageBox.Show("로그아웃 하시겠습니까?", "로그아웃", MessageBoxButtons.YesNo)
        If result = DialogResult.Yes Then
            isLoggedIn = False

            ' 로그아웃 메시지 출력
            MessageBox.Show("로그아웃되었습니다.")

            ' 메인 폼으로 돌아가기
            Dim mainForm As New mainForm()
            mainForm.Show()
            Me.Close()

        End If
    End Sub

End Class