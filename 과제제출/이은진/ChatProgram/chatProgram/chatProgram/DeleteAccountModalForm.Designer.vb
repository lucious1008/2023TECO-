<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class DeleteAccountModalForm
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
        closeBtn = New Button()
        Label2 = New Label()
        Button1 = New Button()
        SuspendLayout()
        ' 
        ' Label1
        ' 
        Label1.AutoSize = True
        Label1.Font = New Font("Malgun Gothic", 30F, FontStyle.Bold, GraphicsUnit.Point)
        Label1.ForeColor = SystemColors.Highlight
        Label1.Location = New Point(163, 97)
        Label1.Name = "Label1"
        Label1.Size = New Size(235, 67)
        Label1.TabIndex = 1
        Label1.Text = "会員退会"
        ' 
        ' closeBtn
        ' 
        closeBtn.Font = New Font("Malgun Gothic", 13F, FontStyle.Regular, GraphicsUnit.Point)
        closeBtn.Location = New Point(291, 456)
        closeBtn.Name = "closeBtn"
        closeBtn.Size = New Size(198, 55)
        closeBtn.TabIndex = 4
        closeBtn.Text = "閉じる"
        closeBtn.UseVisualStyleBackColor = True
        ' 
        ' Label2
        ' 
        Label2.AutoSize = True
        Label2.Font = New Font("Malgun Gothic", 13.8F, FontStyle.Bold, GraphicsUnit.Point)
        Label2.Location = New Point(12, 280)
        Label2.Name = "Label2"
        Label2.Size = New Size(543, 62)
        Label2.TabIndex = 5
        Label2.Text = "TECO Chatをご利用頂きありがとうございます。" & vbCrLf & "もっと良いサービスを提供するように労力します。" & vbCrLf
        ' 
        ' Button1
        ' 
        Button1.Font = New Font("Malgun Gothic", 13F, FontStyle.Regular, GraphicsUnit.Point)
        Button1.Location = New Point(68, 456)
        Button1.Name = "Button1"
        Button1.Size = New Size(198, 55)
        Button1.TabIndex = 6
        Button1.Text = "退会"
        Button1.UseVisualStyleBackColor = True
        ' 
        ' DeleteAccountModalForm
        ' 
        AutoScaleDimensions = New SizeF(9F, 20F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(558, 653)
        Controls.Add(Button1)
        Controls.Add(Label2)
        Controls.Add(closeBtn)
        Controls.Add(Label1)
        Name = "DeleteAccountModalForm"
        Text = "DeleteAccountModalForm"
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents closeBtn As Button
    Friend WithEvents Label2 As Label
    Friend WithEvents Button1 As Button
End Class
