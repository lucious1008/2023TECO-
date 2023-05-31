Imports MySql.Data.MySqlClient

Public Class DbConnectionClass
        Private Shared instance As DbConnectionClass
        Private connStr As String
        Private conn As MySqlConnection

    Public Sub New(server As String, port As Integer, database As String, user As String, password As String)
        connStr = $"server=127.0.0.1;port=3306;database=chat;user=teco;password=teco1234!;"
        conn = New MySqlConnection(connStr)
    End Sub

    Public Shared Function GetInstance(server As String, port As Integer, database As String, user As String, password As String) As DbConnectionClass
            If instance Is Nothing Then
                instance = New DbConnectionClass(server, port, database, user, password)
            End If
            Return instance
        End Function

        Public Function OpenConnection() As Boolean
            Try
                conn.Open()
                Return True
            Catch ex As Exception
                MessageBox.Show("데이터베이스 연결을 열 수 없습니다: " & ex.Message)
                Return False
            End Try
        End Function

        Public Sub CloseConnection()
            conn.Close()
        End Sub

    Public Function IsConnectionOpen() As Boolean
        Return conn.State = ConnectionState.Open
    End Function

    Public Function ExecuteNonQuery(query As String) As Integer
            Dim rowsAffected As Integer = 0
            Try
                Using command As New MySqlCommand(query, conn)
                    rowsAffected = command.ExecuteNonQuery()
                End Using
            Catch ex As Exception
                MessageBox.Show("쿼리를 실행하는 중에 오류가 발생했습니다: " & ex.Message)
            End Try
            Return rowsAffected
        End Function

        Public Function GetConnection() As MySqlConnection
            Return conn
        End Function

    End Class

