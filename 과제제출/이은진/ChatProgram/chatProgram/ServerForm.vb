Imports System.Net
Imports System.Net.Sockets
Imports System.Text
Imports System.Threading

Public Class ServerForm
    Private serverSocket As Socket
    Private clientSockets As List(Of Socket)

    Public Sub New()
        InitializeComponent()
    End Sub

    Private Sub ServerForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Dim serverThread As New Thread(AddressOf StartServer)
        serverThread.Start()
    End Sub

    Private Sub StartServer()
        Try
            serverSocket = New Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp)
            serverSocket.Bind(New IPEndPoint(IPAddress.Any, 12345))
            serverSocket.Listen(10)

            clientSockets = New List(Of Socket)()

            While True
                Dim clientSocket As Socket = serverSocket.Accept()
                clientSockets.Add(clientSocket)

                Dim communicationThread As New Thread(AddressOf HandleClientCommunication)
                communicationThread.Start(clientSocket)
            End While
        Catch ex As Exception
            MessageBox.Show("서버 시작 중에 오류가 발생했습니다: " & ex.Message)
        End Try
    End Sub

    Private Sub HandleClientCommunication(clientSocket As Socket)
        Try
            Dim buffer As Byte() = New Byte(1023) {}
            While True
                Dim bytesRead As Integer = clientSocket.Receive(buffer)
                If bytesRead > 0 Then
                    Dim receivedMessage As String = Encoding.UTF8.GetString(buffer, 0, bytesRead)
                    Dim processedMessage As String = ProcessMessage(receivedMessage)
                    SendToOtherClients(processedMessage, clientSocket)
                End If
            End While
        Catch ex As Exception
            MessageBox.Show("클라이언트 통신 중에 오류가 발생했습니다: " & ex.Message)
            clientSockets.Remove(clientSocket)
            clientSocket.Close()
        End Try
    End Sub

    Private Function ProcessMessage(message As String) As String
        ' 메시지 처리 로직을 추가하세요.
        Return message
    End Function

    Private Sub SendToOtherClients(message As String, senderSocket As Socket)
        For Each clientSocket As Socket In clientSockets
            If clientSocket IsNot senderSocket Then
                clientSocket.Send(Encoding.UTF8.GetBytes(message))
            End If
        Next
    End Sub
End Class
