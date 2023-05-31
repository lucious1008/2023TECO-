<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class ChangeNickModalForm
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
        Label2 = New Label()
        Label3 = New Label()
        CurrentNick = New Label()
        ChgNickInput = New TextBox()
        Label5 = New Label()
        closeBtn = New Button()
        nickChgBtn = New Button()
        SuspendLayout()
        ' 
        ' Label1
        ' 
        Label1.AutoSize = True
        Label1.Font = New Font("Malgun Gothic", 30F, FontStyle.Bold, GraphicsUnit.Point)
        Label1.ForeColor = SystemColors.Highlight
        Label1.Location = New Point(71, 77)
        Label1.Name = "Label1"
        Label1.Size = New Size(425, 67)
        Label1.TabIndex = 0
        Label1.Text = "ニックネーム変更"
        ' 
        ' Label2
        ' 
        Label2.AutoSize = True
        Label2.Font = New Font("Malgun Gothic", 15F, FontStyle.Regular, GraphicsUnit.Point)
        Label2.Location = New Point(34, 304)
        Label2.Name = "Label2"
        Label2.Size = New Size(236, 35)
        Label2.TabIndex = 1
        Label2.Text = "現在ニックネーム："
        ' 
        ' Label3
        ' 
        Label3.AutoSize = True
        Label3.Font = New Font("Malgun Gothic", 15F, FontStyle.Regular, GraphicsUnit.Point)
        Label3.Location = New Point(33, 419)
        Label3.Name = "Label3"
        Label3.Size = New Size(237, 35)
        Label3.TabIndex = 2
        Label3.Text = "変更ニックネーム："
        ' 
        ' CurrentNick
        ' 
        CurrentNick.AutoSize = True
        CurrentNick.Location = New Point(351, 319)
        CurrentNick.Name = "CurrentNick"
        CurrentNick.Size = New Size(53, 20)
        CurrentNick.TabIndex = 3
        CurrentNick.Text = "Label4"
        ' 
        ' ChgNickInput
        ' 
        ChgNickInput.Location = New Point(276, 427)
        ChgNickInput.Name = "ChgNickInput"
        ChgNickInput.Size = New Size(240, 27)
        ChgNickInput.TabIndex = 4
        ' 
        ' Label5
        ' 
        Label5.AutoSize = True
        Label5.Location = New Point(149, 175)
        Label5.Name = "Label5"
        Label5.Size = New Size(274, 20)
        Label5.TabIndex = 5
        Label5.Text = "ユーザーニックネーム変更ができます。"
        ' 
        ' closeBtn
        ' 
        closeBtn.Font = New Font("Malgun Gothic", 13F, FontStyle.Regular, GraphicsUnit.Point)
        closeBtn.Location = New Point(287, 546)
        closeBtn.Name = "closeBtn"
        closeBtn.Size = New Size(196, 58)
        closeBtn.TabIndex = 7
        closeBtn.Text = "閉じる"
        closeBtn.UseVisualStyleBackColor = True
        ' 
        ' nickChgBtn
        ' 
        nickChgBtn.Font = New Font("Malgun Gothic", 13F, FontStyle.Regular, GraphicsUnit.Point)
        nickChgBtn.Location = New Point(71, 546)
        nickChgBtn.Name = "nickChgBtn"
        nickChgBtn.Size = New Size(199, 58)
        nickChgBtn.TabIndex = 8
        nickChgBtn.Text = "確認"
        nickChgBtn.UseVisualStyleBackColor = True
        ' 
        ' ChangeNickModalForm
        ' 
        AutoScaleDimensions = New SizeF(9F, 20F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(558, 653)
        Controls.Add(nickChgBtn)
        Controls.Add(closeBtn)
        Controls.Add(Label5)
        Controls.Add(ChgNickInput)
        Controls.Add(CurrentNick)
        Controls.Add(Label3)
        Controls.Add(Label2)
        Controls.Add(Label1)
        Name = "ChangeNickModalForm"
        Text = "ChangeNickModalForm"
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents CurrentNick As Label
    Friend WithEvents ChgNickInput As TextBox
    Friend WithEvents Label5 As Label
    Friend WithEvents closeBtn As Button
    Friend WithEvents nickChgBtn As Button
End Class
