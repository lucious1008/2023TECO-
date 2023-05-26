<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class HistoryChatModalForm
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
        ListBox1 = New ListBox()
        closeBtn = New Button()
        SuspendLayout()
        ' 
        ' Label1
        ' 
        Label1.AutoSize = True
        Label1.Font = New Font("Malgun Gothic", 30.0F, FontStyle.Bold, GraphicsUnit.Point)
        Label1.ForeColor = SystemColors.Highlight
        Label1.Location = New Point(114, 37)
        Label1.Name = "Label1"
        Label1.Size = New Size(332, 67)
        Label1.TabIndex = 0
        Label1.Text = "チャット履歴"
        ' 
        ' ListBox1
        ' 
        ListBox1.FormattingEnabled = True
        ListBox1.ItemHeight = 20
        ListBox1.Location = New Point(91, 144)
        ListBox1.Name = "ListBox1"
        ListBox1.Size = New Size(376, 344)
        ListBox1.TabIndex = 1
        ' 
        ' closeBtn
        ' 
        closeBtn.Font = New Font("Malgun Gothic", 13.0F, FontStyle.Regular, GraphicsUnit.Point)
        closeBtn.Location = New Point(146, 541)
        closeBtn.Name = "closeBtn"
        closeBtn.Size = New Size(251, 58)
        closeBtn.TabIndex = 3
        closeBtn.Text = "閉じる"
        closeBtn.UseVisualStyleBackColor = True
        ' 
        ' HistoryChatModalForm
        ' 
        AutoScaleDimensions = New SizeF(9.0F, 20.0F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(558, 653)
        Controls.Add(closeBtn)
        Controls.Add(ListBox1)
        Controls.Add(Label1)
        Name = "HistoryChatModalForm"
        Text = "HistoryChatModalForm"
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents ListBox1 As ListBox
    Friend WithEvents closeBtn As Button
End Class
