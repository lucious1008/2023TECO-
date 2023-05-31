Imports MySql.Data.MySqlClient

Public Class MypageForm
    Private WithEvents deleteAccountModalForm As DeleteAccountModalForm
    Private currentUser As String

    Public Sub New()
    End Sub

    Public Sub New(currentUser As String)
        InitializeComponent()
        Me.currentUser = currentUser
    End Sub

    Public Sub SetCurrentUser(userId As String)
        currentUser = userId
    End Sub

    Private Sub Usermod_Click(sender As Object, e As EventArgs) Handles Usermod.Click
        Dim userModalForm As New UserModalForm(currentUser)
        userModalForm.ShowDialog()
    End Sub

    Private Sub Allusermod_Click(sender As Object, e As EventArgs) Handles Allusermod.Click
        Dim allUserModalForm As New AllUserModalForm(currentUser)
        allUserModalForm.ShowDialog()
    End Sub

    Private Sub Hischatmod_Click(sender As Object, e As EventArgs) Handles Hischatmod.Click
        Dim historyChatModalForm As New HistoryChatModalForm(currentUser)
        historyChatModalForm.ShowDialog()
    End Sub

    Private Sub Chgnickmod_Click(sender As Object, e As EventArgs) Handles Chgnickmod.Click
        Dim changeNickModalForm As New ChangeNickModalForm(currentUser)
        changeNickModalForm.ShowDialog()
    End Sub

    Private Sub DeleteAccountBtn_Click(sender As Object, e As EventArgs) Handles Delaccmod.Click
        deleteAccountModalForm = New DeleteAccountModalForm(currentUser)
        deleteAccountModalForm.ShowDialog()
    End Sub

    Private Sub backPageBtn_Click(sender As Object, e As EventArgs) Handles backPageBtn.Click
        Dim chattingForm As New ChattingForm(currentUser)
        chattingForm.Show()
        Me.Hide()
    End Sub

End Class
