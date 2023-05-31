Public Class AllUserModalForm
    Private currentUser As String

    Public Sub New(currentUser As String)
        Me.currentUser = currentUser
    End Sub

    Private Sub closeBtn_Click(sender As Object, e As EventArgs) Handles closeBtn.Click
        Close()
    End Sub
End Class