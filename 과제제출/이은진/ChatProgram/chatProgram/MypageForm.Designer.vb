<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class MypageForm
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
        Label1 = New Label()
        lb_nick = New Label()
        Usermod = New Button()
        Hischatmod = New Button()
        Chgnickmod = New Button()
        Delaccmod = New Button()
        Allusermod = New Button()
        backPageBtn = New Button()
        SuspendLayout()
        ' 
        ' Label1
        ' 
        Label1.AutoSize = True
        Label1.Font = New Font("Malgun Gothic", 40.2F, FontStyle.Bold, GraphicsUnit.Point)
        Label1.ForeColor = SystemColors.Highlight
        Label1.Location = New Point(128, 33)
        Label1.Name = "Label1"
        Label1.Size = New Size(295, 89)
        Label1.TabIndex = 0
        Label1.Text = "MyPage"
        ' 
        ' lb_nick
        ' 
        lb_nick.AutoSize = True
        lb_nick.Font = New Font("Malgun Gothic", 12.0F, FontStyle.Regular, GraphicsUnit.Point)
        lb_nick.Location = New Point(168, 180)
        lb_nick.Name = "lb_nick"
        lb_nick.Size = New Size(104, 28)
        lb_nick.TabIndex = 1
        lb_nick.Text = "Welcome "
        ' 
        ' Usermod
        ' 
        Usermod.Location = New Point(98, 255)
        Usermod.Name = "Usermod"
        Usermod.Size = New Size(364, 48)
        Usermod.TabIndex = 2
        Usermod.Text = "ユーザー情報"
        Usermod.UseVisualStyleBackColor = True
        ' 
        ' Hischatmod
        ' 
        Hischatmod.Location = New Point(98, 400)
        Hischatmod.Name = "Hischatmod"
        Hischatmod.Size = New Size(364, 48)
        Hischatmod.TabIndex = 3
        Hischatmod.Text = "チャット履歴"
        Hischatmod.UseVisualStyleBackColor = True
        ' 
        ' Chgnickmod
        ' 
        Chgnickmod.Location = New Point(98, 470)
        Chgnickmod.Name = "Chgnickmod"
        Chgnickmod.Size = New Size(364, 48)
        Chgnickmod.TabIndex = 4
        Chgnickmod.Text = "ニックネーム変更"
        Chgnickmod.UseVisualStyleBackColor = True
        ' 
        ' Delaccmod
        ' 
        Delaccmod.Location = New Point(97, 543)
        Delaccmod.Name = "Delaccmod"
        Delaccmod.Size = New Size(364, 48)
        Delaccmod.TabIndex = 5
        Delaccmod.Text = "会員退会"
        Delaccmod.UseVisualStyleBackColor = True
        ' 
        ' Allusermod
        ' 
        Allusermod.Location = New Point(98, 327)
        Allusermod.Name = "Allusermod"
        Allusermod.Size = New Size(364, 48)
        Allusermod.TabIndex = 6
        Allusermod.Text = "全体ユーザー情報"
        Allusermod.UseVisualStyleBackColor = True
        ' 
        ' backPageBtn
        ' 
        backPageBtn.Location = New Point(439, 33)
        backPageBtn.Name = "backPageBtn"
        backPageBtn.Size = New Size(94, 29)
        backPageBtn.TabIndex = 7
        backPageBtn.Text = "戻る"
        backPageBtn.UseVisualStyleBackColor = True
        ' 
        ' MypageForm
        ' 
        AutoScaleDimensions = New SizeF(9.0F, 20.0F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(558, 653)
        Controls.Add(backPageBtn)
        Controls.Add(Allusermod)
        Controls.Add(Delaccmod)
        Controls.Add(Chgnickmod)
        Controls.Add(Hischatmod)
        Controls.Add(Usermod)
        Controls.Add(lb_nick)
        Controls.Add(Label1)
        Name = "MypageForm"
        Text = "MypageForm"
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents lb_nick As Label
    Friend WithEvents Usermod As Button
    Friend WithEvents Hischatmod As Button
    Friend WithEvents Chgnickmod As Button
    Friend WithEvents Delaccmod As Button
    Friend WithEvents Allusermod As Button
    Friend WithEvents backPageBtn As Button
End Class
