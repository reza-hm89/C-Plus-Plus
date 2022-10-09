namespace Graph1
{
    partial class frmSearch
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
            this.lblMembershipNo = new System.Windows.Forms.Label();
            this.txtMembershipNo = new System.Windows.Forms.TextBox();
            this.btnSearch = new System.Windows.Forms.Button();
            this.txtFamily = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // lblMembershipNo
            // 
            this.lblMembershipNo.AutoSize = true;
            this.lblMembershipNo.Font = new System.Drawing.Font("B Mitra", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.lblMembershipNo.Location = new System.Drawing.Point(162, 42);
            this.lblMembershipNo.Name = "lblMembershipNo";
            this.lblMembershipNo.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.lblMembershipNo.Size = new System.Drawing.Size(86, 21);
            this.lblMembershipNo.TabIndex = 7;
            this.lblMembershipNo.Text = "شماره عضویت :";
            this.lblMembershipNo.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // txtMembershipNo
            // 
            this.txtMembershipNo.Font = new System.Drawing.Font("B Traffic", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.txtMembershipNo.ForeColor = System.Drawing.Color.RoyalBlue;
            this.txtMembershipNo.Location = new System.Drawing.Point(68, 66);
            this.txtMembershipNo.MaxLength = 10;
            this.txtMembershipNo.Multiline = true;
            this.txtMembershipNo.Name = "txtMembershipNo";
            this.txtMembershipNo.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.txtMembershipNo.Size = new System.Drawing.Size(118, 40);
            this.txtMembershipNo.TabIndex = 6;
            this.txtMembershipNo.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.txtMembershipNo.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtMembershipNo_KeyPress);
            // 
            // btnSearch
            // 
            this.btnSearch.Font = new System.Drawing.Font("B Nazanin", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.btnSearch.Location = new System.Drawing.Point(95, 122);
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.Size = new System.Drawing.Size(65, 32);
            this.btnSearch.TabIndex = 8;
            this.btnSearch.Text = "جستجو";
            this.btnSearch.UseVisualStyleBackColor = true;
            this.btnSearch.Click += new System.EventHandler(this.btnSearch_Click);
            // 
            // txtFamily
            // 
            this.txtFamily.Font = new System.Drawing.Font("B Traffic", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.txtFamily.ForeColor = System.Drawing.Color.RoyalBlue;
            this.txtFamily.Location = new System.Drawing.Point(68, 66);
            this.txtFamily.MaxLength = 10;
            this.txtFamily.Multiline = true;
            this.txtFamily.Name = "txtFamily";
            this.txtFamily.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.txtFamily.Size = new System.Drawing.Size(118, 40);
            this.txtFamily.TabIndex = 9;
            // 
            // frmSearch
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(266, 184);
            this.Controls.Add(this.btnSearch);
            this.Controls.Add(this.lblMembershipNo);
            this.Controls.Add(this.txtMembershipNo);
            this.Controls.Add(this.txtFamily);
            this.MaximizeBox = false;
            this.Name = "frmSearch";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "جستجو";
            this.Load += new System.EventHandler(this.frmSearch_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblMembershipNo;
        private System.Windows.Forms.TextBox txtMembershipNo;
        private System.Windows.Forms.Button btnSearch;
        private System.Windows.Forms.TextBox txtFamily;

    }
}