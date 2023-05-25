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
        Label2 = New Label()
        Label3 = New Label()
        Label4 = New Label()
        TextBox1 = New TextBox()
        TextBox2 = New TextBox()
        BackgroundWorker1 = New ComponentModel.BackgroundWorker()
        Button1 = New Button()
        SuspendLayout()
        ' 
        ' Label1
        ' 
        Label1.AutoSize = True
        Label1.Font = New Font("Yu Gothic UI", 50F, FontStyle.Regular, GraphicsUnit.Point)
        Label1.ForeColor = SystemColors.Highlight
        Label1.Location = New Point(99, 43)
        Label1.Name = "Label1"
        Label1.Size = New Size(202, 89)
        Label1.TabIndex = 0
        Label1.Text = "Login"
        ' 
        ' Label2
        ' 
        Label2.AutoSize = True
        Label2.Location = New Point(325, 177)
        Label2.Name = "Label2"
        Label2.Size = New Size(0, 15)
        Label2.TabIndex = 1
        ' 
        ' Label3
        ' 
        Label3.AutoSize = True
        Label3.Font = New Font("Yu Gothic UI", 18F, FontStyle.Regular, GraphicsUnit.Point)
        Label3.Location = New Point(31, 286)
        Label3.Name = "Label3"
        Label3.Size = New Size(61, 32)
        Label3.TabIndex = 2
        Label3.Text = "PW :"
        ' 
        ' Label4
        ' 
        Label4.AutoSize = True
        Label4.Font = New Font("Yu Gothic UI", 18F, FontStyle.Regular, GraphicsUnit.Point)
        Label4.Location = New Point(43, 202)
        Label4.Name = "Label4"
        Label4.Size = New Size(56, 32)
        Label4.TabIndex = 3
        Label4.Text = "ID : "
        ' 
        ' TextBox1
        ' 
        TextBox1.Location = New Point(105, 211)
        TextBox1.Name = "TextBox1"
        TextBox1.Size = New Size(219, 23)
        TextBox1.TabIndex = 4
        ' 
        ' TextBox2
        ' 
        TextBox2.Location = New Point(104, 293)
        TextBox2.Name = "TextBox2"
        TextBox2.Size = New Size(218, 23)
        TextBox2.TabIndex = 5
        ' 
        ' Button1
        ' 
        Button1.AutoSize = True
        Button1.Font = New Font("Yu Gothic UI", 15F, FontStyle.Regular, GraphicsUnit.Point)
        Button1.ForeColor = SystemColors.MenuHighlight
        Button1.Location = New Point(118, 376)
        Button1.Name = "Button1"
        Button1.Size = New Size(157, 43)
        Button1.TabIndex = 6
        Button1.Text = "確認"
        Button1.UseVisualStyleBackColor = True
        ' 
        ' LoginForm
        ' 
        AutoScaleDimensions = New SizeF(7F, 15F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(397, 454)
        Controls.Add(Button1)
        Controls.Add(TextBox2)
        Controls.Add(TextBox1)
        Controls.Add(Label4)
        Controls.Add(Label3)
        Controls.Add(Label2)
        Controls.Add(Label1)
        Name = "LoginForm"
        Text = "LoginForm"
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents TextBox1 As TextBox
    Friend WithEvents TextBox2 As TextBox
    Friend WithEvents BackgroundWorker1 As System.ComponentModel.BackgroundWorker
    Friend WithEvents Button1 As Button
End Class
