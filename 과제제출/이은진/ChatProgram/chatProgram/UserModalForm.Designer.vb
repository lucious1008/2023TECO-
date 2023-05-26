<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class UserModalForm
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
        closeBtn = New Button()
        Label3 = New Label()
        Label4 = New Label()
        LeadId = New Label()
        PwInputChg = New TextBox()
        ReadNick = New Label()
        PwConfirmChg = New Button()
        Label7 = New Label()
        SuspendLayout()
        ' 
        ' Label1
        ' 
        Label1.AutoSize = True
        Label1.Font = New Font("Malgun Gothic", 30F, FontStyle.Bold, GraphicsUnit.Point)
        Label1.ForeColor = SystemColors.Highlight
        Label1.Location = New Point(120, 73)
        Label1.Name = "Label1"
        Label1.Size = New Size(315, 67)
        Label1.TabIndex = 0
        Label1.Text = "ユーザー情報"
        ' 
        ' Label2
        ' 
        Label2.AutoSize = True
        Label2.Font = New Font("Malgun Gothic", 15F, FontStyle.Regular, GraphicsUnit.Point)
        Label2.Location = New Point(99, 235)
        Label2.Name = "Label2"
        Label2.Size = New Size(54, 35)
        Label2.TabIndex = 1
        Label2.Text = "ID :"
        ' 
        ' closeBtn
        ' 
        closeBtn.Font = New Font("Malgun Gothic", 13F, FontStyle.Regular, GraphicsUnit.Point)
        closeBtn.Location = New Point(153, 493)
        closeBtn.Name = "closeBtn"
        closeBtn.Size = New Size(251, 58)
        closeBtn.TabIndex = 2
        closeBtn.Text = "閉じる"
        closeBtn.UseVisualStyleBackColor = True
        ' 
        ' Label3
        ' 
        Label3.AutoSize = True
        Label3.Font = New Font("Malgun Gothic", 15F, FontStyle.Regular, GraphicsUnit.Point)
        Label3.Location = New Point(86, 304)
        Label3.Name = "Label3"
        Label3.Size = New Size(67, 35)
        Label3.TabIndex = 3
        Label3.Text = "PW :"
        ' 
        ' Label4
        ' 
        Label4.AutoSize = True
        Label4.Font = New Font("Malgun Gothic", 13F, FontStyle.Regular, GraphicsUnit.Point)
        Label4.Location = New Point(29, 411)
        Label4.Name = "Label4"
        Label4.Size = New Size(124, 30)
        Label4.TabIndex = 4
        Label4.Text = "Nickname :"
        ' 
        ' LeadId
        ' 
        LeadId.AutoSize = True
        LeadId.Location = New Point(242, 248)
        LeadId.Name = "LeadId"
        LeadId.Size = New Size(53, 20)
        LeadId.TabIndex = 5
        LeadId.Text = "Label5"
        ' 
        ' PwInputChg
        ' 
        PwInputChg.Location = New Point(179, 312)
        PwInputChg.Name = "PwInputChg"
        PwInputChg.Size = New Size(211, 27)
        PwInputChg.TabIndex = 6
        ' 
        ' ReadNick
        ' 
        ReadNick.AutoSize = True
        ReadNick.Location = New Point(242, 421)
        ReadNick.Name = "ReadNick"
        ReadNick.Size = New Size(53, 20)
        ReadNick.TabIndex = 7
        ReadNick.Text = "Label6"
        ' 
        ' PwConfirmChg
        ' 
        PwConfirmChg.Location = New Point(415, 313)
        PwConfirmChg.Name = "PwConfirmChg"
        PwConfirmChg.Size = New Size(94, 29)
        PwConfirmChg.TabIndex = 8
        PwConfirmChg.Text = "確認"
        PwConfirmChg.UseVisualStyleBackColor = True
        ' 
        ' Label7
        ' 
        Label7.AutoSize = True
        Label7.Location = New Point(242, 351)
        Label7.Name = "Label7"
        Label7.Size = New Size(53, 20)
        Label7.TabIndex = 9
        Label7.Text = "Label7"
        ' 
        ' UserModalForm
        ' 
        AutoScaleDimensions = New SizeF(9F, 20F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(558, 653)
        Controls.Add(Label7)
        Controls.Add(PwConfirmChg)
        Controls.Add(ReadNick)
        Controls.Add(PwInputChg)
        Controls.Add(LeadId)
        Controls.Add(Label4)
        Controls.Add(Label3)
        Controls.Add(closeBtn)
        Controls.Add(Label2)
        Controls.Add(Label1)
        Name = "UserModalForm"
        Text = "UserModalForm"
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents closeBtn As Button
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents LeadId As Label
    Friend WithEvents PwInputChg As TextBox
    Friend WithEvents ReadNick As Label
    Friend WithEvents PwConfirmChg As Button
    Friend WithEvents Label7 As Label
End Class
