namespace Graph1
{
    partial class frmExtend
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
            this.label8 = new System.Windows.Forms.Label();
            this.cmbCreditAccount = new System.Windows.Forms.ComboBox();
            this.btnExtend = new System.Windows.Forms.Button();
            this.txtMembershipNo = new System.Windows.Forms.TextBox();
            this.lblMemberShipDate = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("B Mitra", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.label8.Location = new System.Drawing.Point(192, 110);
            this.label8.Name = "label8";
            this.label8.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label8.Size = new System.Drawing.Size(65, 21);
            this.label8.TabIndex = 13;
            this.label8.Text = "مبلغ اعتبار :";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // cmbCreditAccount
            // 
            this.cmbCreditAccount.Font = new System.Drawing.Font("B Mitra", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.cmbCreditAccount.FormattingEnabled = true;
            this.cmbCreditAccount.Items.AddRange(new object[] {
            "2000",
            "4000",
            "6000",
            "8000"});
            this.cmbCreditAccount.Location = new System.Drawing.Point(53, 102);
            this.cmbCreditAccount.Name = "cmbCreditAccount";
            this.cmbCreditAccount.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.cmbCreditAccount.Size = new System.Drawing.Size(121, 35);
            this.cmbCreditAccount.TabIndex = 12;
            this.cmbCreditAccount.Text = "2000";
            // 
            // btnExtend
            // 
            this.btnExtend.Location = new System.Drawing.Point(112, 154);
            this.btnExtend.Name = "btnExtend";
            this.btnExtend.Size = new System.Drawing.Size(75, 23);
            this.btnExtend.TabIndex = 14;
            this.btnExtend.Text = "تمدید";
            this.btnExtend.UseVisualStyleBackColor = true;
            this.btnExtend.Click += new System.EventHandler(this.btnExtend_Click);
            // 
            // txtMembershipNo
            // 
            this.txtMembershipNo.Font = new System.Drawing.Font("B Nazanin", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.txtMembershipNo.ForeColor = System.Drawing.Color.RoyalBlue;
            this.txtMembershipNo.Location = new System.Drawing.Point(53, 59);
            this.txtMembershipNo.MaxLength = 10;
            this.txtMembershipNo.Multiline = true;
            this.txtMembershipNo.Name = "txtMembershipNo";
            this.txtMembershipNo.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.txtMembershipNo.Size = new System.Drawing.Size(121, 37);
            this.txtMembershipNo.TabIndex = 15;
            this.txtMembershipNo.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.txtMembershipNo.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtMembershipNo_KeyPress);
            // 
            // lblMemberShipDate
            // 
            this.lblMemberShipDate.AutoSize = true;
            this.lblMemberShipDate.Font = new System.Drawing.Font("B Mitra", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.lblMemberShipDate.Location = new System.Drawing.Point(192, 64);
            this.lblMemberShipDate.Name = "lblMemberShipDate";
            this.lblMemberShipDate.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.lblMemberShipDate.Size = new System.Drawing.Size(86, 21);
            this.lblMemberShipDate.TabIndex = 16;
            this.lblMemberShipDate.Text = "شماره عضویت :";
            this.lblMemberShipDate.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // frmExtend
            // 
            this.AcceptButton = this.btnExtend;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(290, 204);
            this.Controls.Add(this.lblMemberShipDate);
            this.Controls.Add(this.txtMembershipNo);
            this.Controls.Add(this.btnExtend);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.cmbCreditAccount);
            this.MinimizeBox = false;
            this.Name = "frmExtend";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Extend";
            this.Load += new System.EventHandler(this.frmExtend_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label8;
        protected System.Windows.Forms.ComboBox cmbCreditAccount;
        private System.Windows.Forms.Button btnExtend;
        private System.Windows.Forms.TextBox txtMembershipNo;
        private System.Windows.Forms.Label lblMemberShipDate;
    }
}