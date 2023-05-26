<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class ChattingForm
    Inherits System.Windows.Forms.Form

    'フォームがコンポーネントの一覧をクリーンアップするために dispose をオーバーライドします。
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows フォーム デザイナーで必要です。
    Private components As System.ComponentModel.IContainer

    'メモ: 以下のプロシージャは Windows フォーム デザイナーで必要です。
    'Windows フォーム デザイナーを使用して変更できます。  
    'コード エディターを使って変更しないでください。
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        ChatSendBtn = New Button()
        ChatInput = New TextBox()
        ChatBox = New ListBox()
        label1 = New Label()
        LogoutBtn = New Button()
        MypageBtn = New Button()
        OnlineUserChk = New ListView()
        Label2 = New Label()
        SuspendLayout()
        ' 
        ' ChatSendBtn
        ' 
        ChatSendBtn.Location = New Point(415, 591)
        ChatSendBtn.Name = "ChatSendBtn"
        ChatSendBtn.Size = New Size(101, 29)
        ChatSendBtn.TabIndex = 0
        ChatSendBtn.Text = "転送"
        ChatSendBtn.UseVisualStyleBackColor = True
        ' 
        ' ChatInput
        ' 
        ChatInput.Location = New Point(42, 592)
        ChatInput.Name = "ChatInput"
        ChatInput.Size = New Size(367, 27)
        ChatInput.TabIndex = 1
        ' 
        ' ChatBox
        ' 
        ChatBox.FormattingEnabled = True
        ChatBox.ItemHeight = 20
        ChatBox.Location = New Point(42, 212)
        ChatBox.Name = "ChatBox"
        ChatBox.Size = New Size(474, 364)
        ChatBox.TabIndex = 2
        ' 
        ' label1
        ' 
        label1.AutoSize = True
        label1.Font = New Font("Malgun Gothic", 10.8F, FontStyle.Bold, GraphicsUnit.Point)
        label1.Location = New Point(42, 164)
        label1.Name = "label1"
        label1.Size = New Size(124, 25)
        label1.TabIndex = 3
        label1.Text = "Tecoチャット"
        ' 
        ' LogoutBtn
        ' 
        LogoutBtn.Location = New Point(422, 12)
        LogoutBtn.Name = "LogoutBtn"
        LogoutBtn.Size = New Size(94, 29)
        LogoutBtn.TabIndex = 4
        LogoutBtn.Text = "Logout"
        LogoutBtn.UseVisualStyleBackColor = True
        ' 
        ' MypageBtn
        ' 
        MypageBtn.Location = New Point(322, 12)
        MypageBtn.Name = "MypageBtn"
        MypageBtn.Size = New Size(94, 29)
        MypageBtn.TabIndex = 5
        MypageBtn.Text = "Mypage"
        MypageBtn.UseVisualStyleBackColor = True
        ' 
        ' OnlineUserChk
        ' 
        OnlineUserChk.Location = New Point(287, 115)
        OnlineUserChk.Name = "OnlineUserChk"
        OnlineUserChk.Size = New Size(229, 91)
        OnlineUserChk.TabIndex = 6
        OnlineUserChk.UseCompatibleStateImageBehavior = False
        ' 
        ' Label2
        ' 
        Label2.AutoSize = True
        Label2.Location = New Point(463, 70)
        Label2.Name = "Label2"
        Label2.Size = New Size(53, 20)
        Label2.TabIndex = 7
        Label2.Text = "Label2"
        ' 
        ' ChattingForm
        ' 
        AutoScaleDimensions = New SizeF(9F, 20F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(558, 653)
        Controls.Add(Label2)
        Controls.Add(OnlineUserChk)
        Controls.Add(MypageBtn)
        Controls.Add(LogoutBtn)
        Controls.Add(label1)
        Controls.Add(ChatBox)
        Controls.Add(ChatInput)
        Controls.Add(ChatSendBtn)
        Name = "ChattingForm"
        Text = "ChattingForm"
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents ChatSendBtn As Button
    Friend WithEvents ChatInput As TextBox
    Friend WithEvents ChatBox As ListBox
    Friend WithEvents label1 As Label
    Friend WithEvents LogoutBtn As Button
    Friend WithEvents MypageBtn As Button
    Friend WithEvents OnlineUserChk As ListView
    Friend WithEvents Label2 As Label
End Class
