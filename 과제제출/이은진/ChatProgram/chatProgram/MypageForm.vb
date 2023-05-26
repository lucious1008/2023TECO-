Public Class MypageForm
    Private Sub Usermod_Click(sender As Object, e As EventArgs) Handles Usermod.Click
        Dim userModalForm As New UserModalForm()

        userModalForm.ShowDialog()
    End Sub

    Private Sub Allusermod_Click(sender As Object, e As EventArgs) Handles Allusermod.Click
        Dim allUserModalForm As New AllUserModalForm()
        allUserModalForm.ShowDialog()
    End Sub

    Private Sub Hischatmod_Click(sender As Object, e As EventArgs) Handles Hischatmod.Click
        Dim historyChatModalForm As New HistoryChatModalForm()
        historyChatModalForm.ShowDialog()
    End Sub

    Private Sub Chgnickmod_Click(sender As Object, e As EventArgs) Handles Chgnickmod.Click
        Dim changeNickModalForm As New ChangeNickModalForm()
        changeNickModalForm.ShowDialog()
    End Sub

    Private Sub Delaccmod_Click(sender As Object, e As EventArgs) Handles Delaccmod.Click
        Dim deleteAccountModalForm As New DeleteAccountModalForm()
        deleteAccountModalForm.ShowDialog()
    End Sub

    Private Sub backPageBtn_Click(sender As Object, e As EventArgs) Handles backPageBtn.Click
        Dim chattingForm As New ChattingForm()
        chattingForm.Show()
        Me.Hide()
    End Sub
End Class