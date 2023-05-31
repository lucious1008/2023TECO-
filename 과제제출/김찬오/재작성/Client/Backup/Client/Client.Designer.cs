namespace Client
{
    partial class Client
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.sendBt = new System.Windows.Forms.Button();
            this.inputTb = new System.Windows.Forms.TextBox();
            this.outputLb = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // sendBt
            // 
            this.sendBt.Location = new System.Drawing.Point(197, 211);
            this.sendBt.Name = "sendBt";
            this.sendBt.Size = new System.Drawing.Size(75, 23);
            this.sendBt.TabIndex = 2;
            this.sendBt.Text = "전 송";
            this.sendBt.UseVisualStyleBackColor = true;
            this.sendBt.Click += new System.EventHandler(this.sendBt_Click);
            // 
            // inputTb
            // 
            this.inputTb.Location = new System.Drawing.Point(12, 211);
            this.inputTb.Name = "inputTb";
            this.inputTb.Size = new System.Drawing.Size(179, 21);
            this.inputTb.TabIndex = 0;
            this.inputTb.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.inputTb_KeyPress);
            // 
            // outputLb
            // 
            this.outputLb.FormattingEnabled = true;
            this.outputLb.ItemHeight = 12;
            this.outputLb.Location = new System.Drawing.Point(13, 13);
            this.outputLb.Name = "outputLb";
            this.outputLb.Size = new System.Drawing.Size(259, 184);
            this.outputLb.TabIndex = 3;
            // 
            // Client
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 244);
            this.Controls.Add(this.outputLb);
            this.Controls.Add(this.inputTb);
            this.Controls.Add(this.sendBt);
            this.Name = "Client";
            this.Text = "연결실패";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Client_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button sendBt;
        private System.Windows.Forms.TextBox inputTb;
        private System.Windows.Forms.ListBox outputLb;
    }
}

