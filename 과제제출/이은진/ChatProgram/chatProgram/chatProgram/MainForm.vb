Public Class MainForm
    Private Sub LoginBtn_Click(sender As Object, e As EventArgs) Handles loginBtn.Click, Login.Click
        Dim loginForm As New LoginForm()
        loginForm.Show()
        Me.Hide()
    End Sub

    Private Sub JoinBtn_Click(sender As Object, e As EventArgs) Handles JoinBtn.Click
        Dim joinForm As New JoinForm()
        joinForm.Show()
        Me.Hide()
    End Sub

End Class