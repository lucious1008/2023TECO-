<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class mainForm
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
        TextBox1 = New TextBox()
        Login = New Button()
        JoinBtn = New Button()
        SuspendLayout()
        ' 
        ' Label1
        ' 
        Label1.AutoSize = True
        Label1.CausesValidation = False
        Label1.Font = New Font("Malgun Gothic", 49.8000031F, FontStyle.Bold, GraphicsUnit.Point)
        Label1.ForeColor = SystemColors.Highlight
        Label1.Location = New Point(46, 59)
        Label1.Name = "Label1"
        Label1.Size = New Size(473, 112)
        Label1.TabIndex = 0
        Label1.Text = "TECO Chat"
        ' 
        ' TextBox1
        ' 
        TextBox1.Location = New Point(76, 207)
        TextBox1.Multiline = True
        TextBox1.Name = "TextBox1"
        TextBox1.Size = New Size(405, 226)
        TextBox1.TabIndex = 1
        TextBox1.Text = "ようこそTECOチャットプラグラムに。" & vbCrLf & "チャットを始める方はログインをしてください。" & vbCrLf
        ' 
        ' Login
        ' 
        Login.AutoSize = True
        Login.Font = New Font("Malgun Gothic", 20.0F, FontStyle.Regular, GraphicsUnit.Point)
        Login.Location = New Point(101, 496)
        Login.Name = "Login"
        Login.Size = New Size(157, 64)
        Login.TabIndex = 2
        Login.Text = "Login"
        Login.UseVisualStyleBackColor = True
        ' 
        ' JoinBtn
        ' 
        JoinBtn.Font = New Font("Malgun Gothic", 20.0F, FontStyle.Regular, GraphicsUnit.Point)
        JoinBtn.Location = New Point(302, 494)
        JoinBtn.Name = "JoinBtn"
        JoinBtn.Size = New Size(165, 66)
        JoinBtn.TabIndex = 3
        JoinBtn.Text = "Join"
        JoinBtn.UseVisualStyleBackColor = True
        ' 
        ' MainForm
        ' 
        AutoScaleDimensions = New SizeF(9.0F, 20.0F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(558, 653)
        Controls.Add(JoinBtn)
        Controls.Add(Login)
        Controls.Add(TextBox1)
        Controls.Add(Label1)
        Name = "MainForm"
        Text = "MainForm"
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents TextBox1 As TextBox
    Friend WithEvents Button1 As Button
    Friend WithEvents Button2 As Button
    Friend WithEvents JoinBtn As Button
    Friend WithEvents Login As Button
End Class
