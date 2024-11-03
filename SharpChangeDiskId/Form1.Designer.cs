namespace SharpChangeDiskId
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.cbProcesses = new System.Windows.Forms.ComboBox();
            this.btnLoadProcesses = new System.Windows.Forms.Button();
            this.btnOK = new System.Windows.Forms.Button();
            this.txtDiskId = new System.Windows.Forms.TextBox();
            this.rbtnRandomDiskID = new System.Windows.Forms.RadioButton();
            this.rbtnGivenDiskId = new System.Windows.Forms.RadioButton();
            this.label2 = new System.Windows.Forms.Label();
            this.errorProvider1 = new System.Windows.Forms.ErrorProvider(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(21, 23);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(83, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "选择目标进程:";
            // 
            // cbProcesses
            // 
            this.cbProcesses.FormattingEnabled = true;
            this.cbProcesses.Location = new System.Drawing.Point(136, 20);
            this.cbProcesses.Name = "cbProcesses";
            this.cbProcesses.Size = new System.Drawing.Size(226, 20);
            this.cbProcesses.TabIndex = 1;
            // 
            // btnLoadProcesses
            // 
            this.btnLoadProcesses.Location = new System.Drawing.Point(378, 20);
            this.btnLoadProcesses.Name = "btnLoadProcesses";
            this.btnLoadProcesses.Size = new System.Drawing.Size(100, 23);
            this.btnLoadProcesses.TabIndex = 2;
            this.btnLoadProcesses.Text = "刷新进程列表";
            this.btnLoadProcesses.UseVisualStyleBackColor = true;
            this.btnLoadProcesses.Click += new System.EventHandler(this.btnLoadProcesses_Click);
            // 
            // btnOK
            // 
            this.btnOK.Location = new System.Drawing.Point(403, 124);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(75, 23);
            this.btnOK.TabIndex = 3;
            this.btnOK.Text = "确定注入";
            this.btnOK.UseVisualStyleBackColor = true;
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // txtDiskId
            // 
            this.txtDiskId.Location = new System.Drawing.Point(136, 83);
            this.txtDiskId.Name = "txtDiskId";
            this.txtDiskId.Size = new System.Drawing.Size(342, 21);
            this.txtDiskId.TabIndex = 4;
            this.txtDiskId.Validated += new System.EventHandler(this.txtDiskId_Validated);
            this.txtDiskId.Validating += new System.ComponentModel.CancelEventHandler(this.txtDiskId_Validating);
            // 
            // rbtnRandomDiskID
            // 
            this.rbtnRandomDiskID.AutoSize = true;
            this.rbtnRandomDiskID.Checked = true;
            this.rbtnRandomDiskID.Location = new System.Drawing.Point(23, 56);
            this.rbtnRandomDiskID.Name = "rbtnRandomDiskID";
            this.rbtnRandomDiskID.Size = new System.Drawing.Size(107, 16);
            this.rbtnRandomDiskID.TabIndex = 5;
            this.rbtnRandomDiskID.TabStop = true;
            this.rbtnRandomDiskID.Text = "随机硬盘序列号";
            this.rbtnRandomDiskID.UseVisualStyleBackColor = true;
            // 
            // rbtnGivenDiskId
            // 
            this.rbtnGivenDiskId.AutoSize = true;
            this.rbtnGivenDiskId.Location = new System.Drawing.Point(23, 83);
            this.rbtnGivenDiskId.Name = "rbtnGivenDiskId";
            this.rbtnGivenDiskId.Size = new System.Drawing.Size(107, 16);
            this.rbtnGivenDiskId.TabIndex = 6;
            this.rbtnGivenDiskId.Text = "指定硬盘序列号";
            this.rbtnGivenDiskId.UseVisualStyleBackColor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(27, 118);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(179, 12);
            this.label2.TabIndex = 7;
            this.label2.Text = "硬盘序列号格式说明:10进制数字";
            // 
            // errorProvider1
            // 
            this.errorProvider1.ContainerControl = this;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(505, 162);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.rbtnGivenDiskId);
            this.Controls.Add(this.rbtnRandomDiskID);
            this.Controls.Add(this.txtDiskId);
            this.Controls.Add(this.btnOK);
            this.Controls.Add(this.btnLoadProcesses);
            this.Controls.Add(this.cbProcesses);
            this.Controls.Add(this.label1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "免重启硬盘序列号修改器,使用于VC程序";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cbProcesses;
        private System.Windows.Forms.Button btnLoadProcesses;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.TextBox txtDiskId;
        private System.Windows.Forms.RadioButton rbtnRandomDiskID;
        private System.Windows.Forms.RadioButton rbtnGivenDiskId;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ErrorProvider errorProvider1;
    }
}

