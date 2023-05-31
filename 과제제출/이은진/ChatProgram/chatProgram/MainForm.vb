Imports MySql.Data.MySqlClient

Public Class mainForm
    Private WithEvents loginForm As LoginForm
    Private WithEvents joinForm As joinForm

    Public Sub New()
        InitializeComponent()
        loginForm = New LoginForm
        joinForm = New joinForm()
    End Sub

    Private Sub LoginBtn_Click(sender As Object, e As EventArgs) Handles Loginbtn.Click
        loginForm.Show()
        Me.Hide()
    End Sub

    Private Sub JoinBtn_Click(sender As Object, e As EventArgs) Handles JoinBtn.Click
        joinForm.Show()
        Me.Hide()
    End Sub

    Private Sub LoginForm_FormClosed(sender As Object, e As FormClosedEventArgs) Handles loginForm.FormClosed
        Me.Show()
    End Sub

    Private Sub JoinForm_FormClosed(sender As Object, e As FormClosedEventArgs) Handles joinForm.FormClosed
        Me.Show()
    End Sub
End Class
