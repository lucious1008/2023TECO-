Public Class UserModalForm
    Private currentUser As String

    Public Sub New(currentUser As String)
        Me.currentUser = currentUser
    End Sub

    Private Sub closeBtn_Click(sender As Object, e As EventArgs) Handles closeBtn.Click
        Close()
    End Sub

    Private Sub PwConfirmChg_Click(sender As Object, e As EventArgs) Handles PwConfirmChg.Click

    End Sub

    Private Sub PwInputChg_TextChanged(sender As Object, e As EventArgs) Handles PwInputChg.TextChanged

    End Sub

    Private Sub ReadNick_Click(sender As Object, e As EventArgs) Handles ReadNick.Click

    End Sub
End Class
