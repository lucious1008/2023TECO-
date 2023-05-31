Imports Microsoft.VisualBasic.ApplicationServices
Imports MySql.Data.MySqlClient
Imports System.Net
Imports System.Net.Sockets
Imports System.Text
Imports System.Threading

Public Class ChattingForm
    Private dbConn As DbConnectionClass
    Private isLoggedIn As Boolean = True
    Private currentUser As String

    Private clientSocket As Socket

    Public Sub New(currentUser As String)
        InitializeComponent()
        dbConn = New DbConnectionClass("127.0.0.1", 3306, "chat", "teco", "teco1234!")
        Me.currentUser = currentUser
    End Sub

    Public Sub SetCurrentUser(userId As String)
        currentUser = userId

    End Sub

    Private Sub ChattingForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        If Not dbConn.OpenConnection() Then
            MessageBox.Show("데이터베이스 연결을 열 수 없습니다.")
        End If
        ShowConnectedUsers()

        ShowCurrentUserId()

        ConnectToServer()
    End Sub

    Private Sub ChattingForm_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        DisconnectFromServer()
        dbConn.CloseConnection()
    End Sub

    Private Sub ShowConnectedUsers()
        Dim query As String = "SELECT Users.Nickname FROM ConnectedUsers INNER JOIN Users ON ConnectedUsers.UserId = Users.UserId"
        Dim command As New MySqlCommand(query, dbConn.GetConnection())

        Try
            Dim reader As MySqlDataReader = command.ExecuteReader()
            While reader.Read()
                Dim nickname As String = reader.GetString("Nickname")

                Dim item As New ListViewItem(nickname)
                OnlineUserChk.Items.Add(item)
            End While
            reader.Close()
        Catch ex As Exception
            MessageBox.Show("접속 중인 유저 정보를 가져오는 중에 오류가 발생하였습니다: " & ex.Message)
        End Try
    End Sub

    Private Sub ShowCurrentUserId()
        currentId.Text = "Welcome " & currentUser
    End Sub

    Private Sub ConnectToServer()
        Try
            clientSocket = New Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp)
            clientSocket.Connect(IPAddress.Parse("127.0.0.1"), 12345)

            Dim loginMessage As String = "LOGIN:" & currentUser
            Dim loginBytes As Byte() = Encoding.UTF8.GetBytes(loginMessage)
            clientSocket.Send(loginBytes)

            Dim receiveBuffer As Byte() = New Byte(1023) {}
            clientSocket.BeginReceive(receiveBuffer, 0, receiveBuffer.Length, SocketFlags.None, AddressOf ReceiveCallback, receiveBuffer)
        Catch ex As Exception
            MessageBox.Show("서버에 연결 중에 오류가 발생했습니다: " & ex.Message)
        End Try
    End Sub

    Private Sub DisconnectFromServer()
        If clientSocket IsNot Nothing AndAlso clientSocket.Connected Then

            Dim logoutMessage As String = "LOGOUT:" & currentUser
            Dim logoutBytes As Byte() = Encoding.UTF8.GetBytes(logoutMessage)
            clientSocket.Send(logoutBytes)

            clientSocket.Close()
        End If
    End Sub

    Private Sub ReceiveCallback(result As IAsyncResult)
        Dim receiveBuffer As Byte() = DirectCast(result.AsyncState, Byte())
        Dim bytesRead As Integer = clientSocket.EndReceive(result)

        If bytesRead > 0 Then
            Dim receivedMessage As String = Encoding.UTF8.GetString(receiveBuffer, 0, bytesRead)
            ProcessReceivedMessage(receivedMessage)
        End If

        clientSocket.BeginReceive(receiveBuffer, 0, receiveBuffer.Length, SocketFlags.None, AddressOf ReceiveCallback, receiveBuffer)
    End Sub

    Private Sub ProcessReceivedMessage(message As String)

    End Sub

    Private Sub SendMessage(message As String)
        Dim sendBuffer As Byte() = Encoding.UTF8.GetBytes(message)
        NetworkStream.Write(sendBuffer, 0, sendBuffer.Length)
    End Sub


    Private Async Function ChatSendBtn_ClickAsync(sender As Object, e As EventArgs) As Task Handles ChatSendBtn.Click
        Dim message As String = ChatInput.Text.Trim()
        Await SendMessage(message)

        ChatInput.Clear()
    End Function


    Private Sub ChatInput_TextChanged(sender As Object, e As EventArgs) Handles ChatInput.TextChanged

    End Sub

    Private Sub ChatSendBtn_Click(sender As Object, e As EventArgs) Handles ChatSendBtn.Click

        Dim chatMessage As String = currentUser & ": " & ChatInput.Text
        SendMessage(chatMessage)
        ChatInput.Clear()
    End Sub

    Private Sub ChatBox_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ChatBox.SelectedIndexChanged

    End Sub

    Private Sub MypageBtn_Click(sender As Object, e As EventArgs) Handles MypageBtn.Click
        If isLoggedIn Then
            Dim mypageForm As New MypageForm(currentUser)
            mypageForm.Show()
            Me.Hide()
        End If
    End Sub

    Private Sub LogoutBtn_Click(sender As Object, e As EventArgs) Handles LogoutBtn.Click
        Dim result As DialogResult = MessageBox.Show("로그아웃 하시겠습니까?", "로그아웃", MessageBoxButtons.YesNo)
        If result = DialogResult.Yes Then
            isLoggedIn = False


            MessageBox.Show("로그아웃되었습니다.")

            Dim mainForm As New mainForm()
            mainForm.Show()
            Me.Close()
        End If
    End Sub

    Private Sub OnlineUserChk_SelectedIndexChanged(sender As Object, e As EventArgs) Handles OnlineUserChk.SelectedIndexChanged

    End Sub
End Class
