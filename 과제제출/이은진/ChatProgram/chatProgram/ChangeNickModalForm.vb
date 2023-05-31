Public Class ChangeNickModalForm
    Private currentUser As String

    Public Sub New(currentUser As String)
        Me.currentUser = currentUser
    End Sub

    Private Sub closeBtn_Click(sender As Object, e As EventArgs) Handles closeBtn.Click
        Close()
    End Sub

    Private Sub ChgNickInput_TextChanged(sender As Object, e As EventArgs) Handles ChgNickInput.TextChanged

    End Sub

    Private Sub nickChgBtn_Click(sender As Object, e As EventArgs) Handles nickChgBtn.Click

    End Sub

    Private Sub CurrentNick_Click(sender As Object, e As EventArgs) Handles CurrentNick.Click

    End Sub
End Class