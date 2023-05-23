<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class LoginForm
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
        TextBox1 = New TextBox()
        TextBox2 = New TextBox()
        Label2 = New Label()
        Label3 = New Label()
        LoginConfirmBtn = New Button()
        SuspendLayout()
        ' 
        ' Label1
        ' 
        Label1.AutoSize = True
        Label1.Font = New Font("Malgun Gothic", 49.8000031F, FontStyle.Bold, GraphicsUnit.Point)
        Label1.ForeColor = SystemColors.Highlight
        Label1.Location = New Point(153, 81)
        Label1.Name = "Label1"
        Label1.Size = New Size(269, 112)
        Label1.TabIndex = 0
        Label1.Text = "Login"
        ' 
        ' TextBox1
        ' 
        TextBox1.Location = New Point(138, 303)
        TextBox1.Name = "TextBox1"
        TextBox1.Size = New Size(311, 27)
        TextBox1.TabIndex = 1
        ' 
        ' TextBox2
        ' 
        TextBox2.Location = New Point(138, 400)
        TextBox2.Name = "TextBox2"
        TextBox2.Size = New Size(311, 27)
        TextBox2.TabIndex = 2
        ' 
        ' Label2
        ' 
        Label2.AutoSize = True
        Label2.Font = New Font("Malgun Gothic", 15F, FontStyle.Regular, GraphicsUnit.Point)
        Label2.Location = New Point(69, 295)
        Label2.Name = "Label2"
        Label2.Size = New Size(63, 35)
        Label2.TabIndex = 3
        Label2.Text = "ID : "
        ' 
        ' Label3
        ' 
        Label3.AutoSize = True
        Label3.Font = New Font("Malgun Gothic", 15F, FontStyle.Regular, GraphicsUnit.Point)
        Label3.Location = New Point(56, 392)
        Label3.Name = "Label3"
        Label3.Size = New Size(76, 35)
        Label3.TabIndex = 4
        Label3.Text = "PW : "
        ' 
        ' LoginConfirmBtn
        ' 
        LoginConfirmBtn.AutoSize = True
        LoginConfirmBtn.Font = New Font("Malgun Gothic", 20F, FontStyle.Regular, GraphicsUnit.Point)
        LoginConfirmBtn.Location = New Point(213, 528)
        LoginConfirmBtn.Name = "LoginConfirmBtn"
        LoginConfirmBtn.Size = New Size(140, 56)
        LoginConfirmBtn.TabIndex = 5
        LoginConfirmBtn.Text = "確認"
        LoginConfirmBtn.UseVisualStyleBackColor = True
        ' 
        ' LoginForm
        ' 
        AutoScaleDimensions = New SizeF(9F, 20F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(558, 653)
        Controls.Add(LoginConfirmBtn)
        Controls.Add(Label3)
        Controls.Add(Label2)
        Controls.Add(TextBox2)
        Controls.Add(TextBox1)
        Controls.Add(Label1)
        Name = "LoginForm"
        Text = "LoginForm"
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents TextBox1 As TextBox
    Friend WithEvents TextBox2 As TextBox
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents LoginConfirmBtn As Button
End Class
