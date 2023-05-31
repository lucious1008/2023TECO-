Imports System.Net.Sockets
Imports System.Text

Public Class ClientForm
    Private clientSocket As TcpClient
    Private networkStream As NetworkStream
    Private receiveBuffer As Byte()

    Public Sub New()
        InitializeComponent()
    End Sub

    Private Sub ConnectToServer()
        Try
            clientSocket = New TcpClient()
            clientSocket.Connect("서버 IP 주소", 12345)
            networkStream = clientSocket.GetStream()

        Catch ex As Exception
            MessageBox.Show("서버 연결 중에 오류가 발생했습니다: " & ex.Message)
        End Try
    End Sub

    Private Async Sub StartReceiving()
        receiveBuffer = New Byte(1023) {}
        While True
            Try
                Dim bytesRead As Integer = Await networkStream.ReadAsync(receiveBuffer, 0, receiveBuffer.Length)
                If bytesRead > 0 Then
                    Dim receivedMessage As String = Encoding.UTF8.GetString(receiveBuffer, 0, bytesRead)

                    ' 수신한 메시지를 처리하는 로직을 추가하세요.
                End If
            Catch ex As Exception
                MessageBox.Show("서버와의 통신 중에 오류가 발생했습니다: " & ex.Message)
                Exit While
            End Try
        End While
    End Sub

    Private Sub SendMessage(message As String)
        Dim sendBuffer As Byte() = Encoding.UTF8.GetBytes(message)
        networkStream.Write(sendBuffer, 0, sendBuffer.Length)
    End Sub

    Private Sub SendMessageButton_Click(sender As Object, e As EventArgs) Handles SendMessageButton.Click
        Dim message As String = MessageTextBox.Text.Trim()
        SendMessage(message)

        MessageTextBox.Clear()
    End Sub

End Class
