Public Class LoginSession
    Private Shared instance As LoginSession
    Private loggedInUser As String

    Private Sub New()
        ' Private 생성자
    End Sub

    Public Shared Function GetInstance() As LoginSession
        If instance Is Nothing Then
            instance = New LoginSession()
        End If
        Return instance
    End Function

    Public Sub SetLoggedInUser(userId As String)
        loggedInUser = userId
    End Sub

    Public Function GetLoggedInUser() As String
        Return loggedInUser
    End Function

    Public Sub ClearSession()
        loggedInUser = Nothing
    End Sub
End Class
