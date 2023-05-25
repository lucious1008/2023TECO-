<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Main
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
        LoginBtn = New Button()
        JoinBtn = New Button()
        SuspendLayout()
        ' 
        ' Label1
        ' 
        Label1.AutoSize = True
        Label1.Font = New Font("Yu Gothic UI", 50.0F, FontStyle.Regular, GraphicsUnit.Point)
        Label1.ForeColor = SystemColors.Highlight
        Label1.Location = New Point(28, 43)
        Label1.Name = "Label1"
        Label1.Size = New Size(353, 89)
        Label1.TabIndex = 0
        Label1.Text = "TECO Chat"
        ' 
        ' TextBox1
        ' 
        TextBox1.Font = New Font("Yu Gothic UI", 9.75F, FontStyle.Regular, GraphicsUnit.Point)
        TextBox1.ForeColor = SystemColors.WindowFrame
        TextBox1.Location = New Point(60, 161)
        TextBox1.Multiline = True
        TextBox1.Name = "TextBox1"
        TextBox1.ReadOnly = True
        TextBox1.Size = New Size(281, 144)
        TextBox1.TabIndex = 2
        TextBox1.Text = "ようこそTECOチャットプログラムに。" & vbCrLf & vbCrLf & "チャットを始めるのはログインが必要です。" & vbCrLf & "IDを持ってない方は会員登録行いください。" & vbCrLf & vbCrLf & "TECOチャットはお互いマーナを守るため、" & vbCrLf & "皆様のご協力をお願いしております。" & vbCrLf
        ' 
        ' LoginBtn
        ' 
        LoginBtn.AutoSize = True
        LoginBtn.Font = New Font("Yu Gothic UI", 25.0F, FontStyle.Regular, GraphicsUnit.Point)
        LoginBtn.ForeColor = SystemColors.Highlight
        LoginBtn.Location = New Point(42, 346)
        LoginBtn.Name = "LoginBtn"
        LoginBtn.Size = New Size(145, 56)
        LoginBtn.TabIndex = 3
        LoginBtn.Text = "Login"
        LoginBtn.UseVisualStyleBackColor = True
        ' 
        ' JoinBtn
        ' 
        JoinBtn.AutoSize = True
        JoinBtn.Font = New Font("Yu Gothic UI", 25.0F, FontStyle.Regular, GraphicsUnit.Point)
        JoinBtn.ForeColor = SystemColors.Highlight
        JoinBtn.Location = New Point(203, 346)
        JoinBtn.Name = "JoinBtn"
        JoinBtn.Size = New Size(148, 56)
        JoinBtn.TabIndex = 4
        JoinBtn.Text = "Join"
        JoinBtn.UseVisualStyleBackColor = True
        ' 
        ' Main
        ' 
        AutoScaleDimensions = New SizeF(7.0F, 15.0F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(397, 454)
        Controls.Add(JoinBtn)
        Controls.Add(LoginBtn)
        Controls.Add(TextBox1)
        Controls.Add(Label1)
        Name = "Main"
        Text = "MainForm"
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents TextBox1 As TextBox
    Friend WithEvents LoginBtn As Button
    Friend WithEvents JoinBtn As Button
End Class
