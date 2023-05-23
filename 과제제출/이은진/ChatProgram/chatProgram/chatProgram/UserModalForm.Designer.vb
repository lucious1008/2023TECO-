<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class UserModalForm
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
        closeBtn = New Button()
        Label3 = New Label()
        Label4 = New Label()
        Label5 = New Label()
        TextBox1 = New TextBox()
        Label6 = New Label()
        Button2 = New Button()
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
        Label4.Location = New Point(29, 370)
        Label4.Name = "Label4"
        Label4.Size = New Size(124, 30)
        Label4.TabIndex = 4
        Label4.Text = "Nickname :"
        ' 
        ' Label5
        ' 
        Label5.AutoSize = True
        Label5.Location = New Point(242, 248)
        Label5.Name = "Label5"
        Label5.Size = New Size(53, 20)
        Label5.TabIndex = 5
        Label5.Text = "Label5"
        ' 
        ' TextBox1
        ' 
        TextBox1.Location = New Point(179, 312)
        TextBox1.Name = "TextBox1"
        TextBox1.Size = New Size(211, 27)
        TextBox1.TabIndex = 6
        ' 
        ' Label6
        ' 
        Label6.AutoSize = True
        Label6.Location = New Point(242, 380)
        Label6.Name = "Label6"
        Label6.Size = New Size(53, 20)
        Label6.TabIndex = 7
        Label6.Text = "Label6"
        ' 
        ' Button2
        ' 
        Button2.Location = New Point(415, 313)
        Button2.Name = "Button2"
        Button2.Size = New Size(94, 29)
        Button2.TabIndex = 8
        Button2.Text = "確認"
        Button2.UseVisualStyleBackColor = True
        ' 
        ' UserModalForm
        ' 
        AutoScaleDimensions = New SizeF(9F, 20F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(558, 653)
        Controls.Add(Button2)
        Controls.Add(Label6)
        Controls.Add(TextBox1)
        Controls.Add(Label5)
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
    Friend WithEvents Label5 As Label
    Friend WithEvents TextBox1 As TextBox
    Friend WithEvents Label6 As Label
    Friend WithEvents Button2 As Button
End Class
