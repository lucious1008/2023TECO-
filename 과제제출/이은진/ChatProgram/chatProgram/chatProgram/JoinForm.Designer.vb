<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class JoinForm
    Inherits System.Windows.Forms.Form

    'フォームがコンポーネントの一覧をクリーンアップするために dispose をオーバーライドします。
    <System.Diagnostics.DebuggerNonUserCode()> _
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
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Label1 = New Label()
        Label2 = New Label()
        Label3 = New Label()
        Label4 = New Label()
        JoinIdInput = New TextBox()
        JoinPwInput = New TextBox()
        JoinNickInput = New TextBox()
        IdconfirmBtn = New Button()
        NickconfirmBtn = New Button()
        JoinConfirmBtn = New Button()
        Label5 = New Label()
        Label6 = New Label()
        Label7 = New Label()
        SuspendLayout()
        ' 
        ' Label1
        ' 
        Label1.AutoSize = True
        Label1.Font = New Font("Malgun Gothic", 49.8000031F, FontStyle.Bold, GraphicsUnit.Point)
        Label1.ForeColor = SystemColors.Highlight
        Label1.Location = New Point(178, 64)
        Label1.Name = "Label1"
        Label1.Size = New Size(209, 112)
        Label1.TabIndex = 0
        Label1.Text = "Join"
        ' 
        ' Label2
        ' 
        Label2.AutoSize = True
        Label2.Font = New Font("Malgun Gothic", 15F, FontStyle.Regular, GraphicsUnit.Point)
        Label2.Location = New Point(64, 253)
        Label2.Name = "Label2"
        Label2.Size = New Size(54, 35)
        Label2.TabIndex = 1
        Label2.Text = "ID :"
        ' 
        ' Label3
        ' 
        Label3.AutoSize = True
        Label3.Font = New Font("Malgun Gothic", 15F, FontStyle.Regular, GraphicsUnit.Point)
        Label3.Location = New Point(54, 353)
        Label3.Name = "Label3"
        Label3.Size = New Size(67, 35)
        Label3.TabIndex = 2
        Label3.Text = "PW :"
        ' 
        ' Label4
        ' 
        Label4.AutoSize = True
        Label4.Font = New Font("Malgun Gothic", 13F, FontStyle.Regular, GraphicsUnit.Point)
        Label4.Location = New Point(21, 456)
        Label4.Name = "Label4"
        Label4.Size = New Size(138, 30)
        Label4.TabIndex = 3
        Label4.Text = "NICKNAME :"
        ' 
        ' JoinIdInput
        ' 
        JoinIdInput.Location = New Point(124, 262)
        JoinIdInput.Name = "JoinIdInput"
        JoinIdInput.Size = New Size(304, 27)
        JoinIdInput.TabIndex = 4
        ' 
        ' JoinPwInput
        ' 
        JoinPwInput.Location = New Point(124, 361)
        JoinPwInput.Name = "JoinPwInput"
        JoinPwInput.Size = New Size(303, 27)
        JoinPwInput.TabIndex = 5
        ' 
        ' JoinNickInput
        ' 
        JoinNickInput.Location = New Point(164, 461)
        JoinNickInput.Name = "JoinNickInput"
        JoinNickInput.Size = New Size(263, 27)
        JoinNickInput.TabIndex = 6
        ' 
        ' IdconfirmBtn
        ' 
        IdconfirmBtn.Location = New Point(448, 261)
        IdconfirmBtn.Name = "IdconfirmBtn"
        IdconfirmBtn.Size = New Size(94, 29)
        IdconfirmBtn.TabIndex = 7
        IdconfirmBtn.Text = "確認"
        IdconfirmBtn.UseVisualStyleBackColor = True
        ' 
        ' NickconfirmBtn
        ' 
        NickconfirmBtn.Location = New Point(446, 461)
        NickconfirmBtn.Name = "NickconfirmBtn"
        NickconfirmBtn.Size = New Size(94, 29)
        NickconfirmBtn.TabIndex = 8
        NickconfirmBtn.Text = "確認"
        NickconfirmBtn.UseVisualStyleBackColor = True
        ' 
        ' JoinConfirmBtn
        ' 
        JoinConfirmBtn.Location = New Point(178, 554)
        JoinConfirmBtn.Name = "JoinConfirmBtn"
        JoinConfirmBtn.Size = New Size(205, 53)
        JoinConfirmBtn.TabIndex = 9
        JoinConfirmBtn.Text = "確認"
        JoinConfirmBtn.UseVisualStyleBackColor = True
        ' 
        ' Label5
        ' 
        Label5.AutoSize = True
        Label5.Location = New Point(73, 311)
        Label5.Name = "Label5"
        Label5.Size = New Size(402, 20)
        Label5.TabIndex = 10
        Label5.Text = "IDは10桁以内の英大文字または数字で入力してください。" & vbCrLf
        ' 
        ' Label6
        ' 
        Label6.AutoSize = True
        Label6.Location = New Point(73, 405)
        Label6.Name = "Label6"
        Label6.Size = New Size(448, 20)
        Label6.TabIndex = 11
        Label6.Text = "パスワードは8~14桁の英大文字または数字で入力してください。"
        ' 
        ' Label7
        ' 
        Label7.AutoSize = True
        Label7.Location = New Point(164, 502)
        Label7.Name = "Label7"
        Label7.Size = New Size(53, 20)
        Label7.TabIndex = 12
        Label7.Text = "Label7"
        ' 
        ' JoinForm
        ' 
        AutoScaleDimensions = New SizeF(9F, 20F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(558, 653)
        Controls.Add(Label7)
        Controls.Add(Label6)
        Controls.Add(Label5)
        Controls.Add(JoinConfirmBtn)
        Controls.Add(NickconfirmBtn)
        Controls.Add(IdconfirmBtn)
        Controls.Add(JoinNickInput)
        Controls.Add(JoinPwInput)
        Controls.Add(JoinIdInput)
        Controls.Add(Label4)
        Controls.Add(Label3)
        Controls.Add(Label2)
        Controls.Add(Label1)
        Name = "JoinForm"
        Text = "JoinForm"
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents JoinIdInput As TextBox
    Friend WithEvents JoinPwInput As TextBox
    Friend WithEvents JoinNickInput As TextBox
    Friend WithEvents IdconfirmBtn As Button
    Friend WithEvents NickconfirmBtn As Button
    Friend WithEvents JoinConfirmBtn As Button
    Friend WithEvents Label5 As Label
    Friend WithEvents Label6 As Label
    Friend WithEvents Label7 As Label
End Class
