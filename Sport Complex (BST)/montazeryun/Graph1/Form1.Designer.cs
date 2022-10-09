namespace Graph1
{
    partial class frmMain
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
            this.btnEnroll = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnExtend = new System.Windows.Forms.Button();
            this.btnEdit = new System.Windows.Forms.Button();
            this.btnList = new System.Windows.Forms.Button();
            this.btnSearch_No = new System.Windows.Forms.Button();
            this.btnSearch_Family = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnEnroll
            // 
            this.btnEnroll.Font = new System.Drawing.Font("B Davat", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.btnEnroll.Location = new System.Drawing.Point(46, 27);
            this.btnEnroll.Name = "btnEnroll";
            this.btnEnroll.Size = new System.Drawing.Size(332, 40);
            this.btnEnroll.TabIndex = 0;
            this.btnEnroll.Text = "ثبت نام عضو";
            this.btnEnroll.UseVisualStyleBackColor = true;
            this.btnEnroll.Click += new System.EventHandler(this.btnEnroll_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Font = new System.Drawing.Font("B Davat", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.btnDelete.Location = new System.Drawing.Point(46, 73);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(332, 40);
            this.btnDelete.TabIndex = 1;
            this.btnDelete.Text = "حذف عضو از باشگاه";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnExtend
            // 
            this.btnExtend.Font = new System.Drawing.Font("B Davat", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.btnExtend.Location = new System.Drawing.Point(46, 119);
            this.btnExtend.Name = "btnExtend";
            this.btnExtend.Size = new System.Drawing.Size(332, 40);
            this.btnExtend.TabIndex = 2;
            this.btnExtend.Text = "تمدید تاریخ اعتبار عضویت";
            this.btnExtend.UseVisualStyleBackColor = true;
            this.btnExtend.Click += new System.EventHandler(this.btnExtend_Click);
            // 
            // btnEdit
            // 
            this.btnEdit.Font = new System.Drawing.Font("B Davat", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.btnEdit.Location = new System.Drawing.Point(46, 165);
            this.btnEdit.Name = "btnEdit";
            this.btnEdit.Size = new System.Drawing.Size(332, 40);
            this.btnEdit.TabIndex = 3;
            this.btnEdit.Text = "ویرایش اطلاعات عضو";
            this.btnEdit.UseVisualStyleBackColor = true;
            this.btnEdit.Click += new System.EventHandler(this.btnEdit_Click);
            // 
            // btnList
            // 
            this.btnList.Font = new System.Drawing.Font("B Davat", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.btnList.Location = new System.Drawing.Point(46, 211);
            this.btnList.Name = "btnList";
            this.btnList.Size = new System.Drawing.Size(332, 40);
            this.btnList.TabIndex = 4;
            this.btnList.Text = "لیست گیری از اعضا\r\n";
            this.btnList.UseVisualStyleBackColor = true;
            this.btnList.Click += new System.EventHandler(this.btnList_Click);
            // 
            // btnSearch_No
            // 
            this.btnSearch_No.Font = new System.Drawing.Font("B Davat", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.btnSearch_No.Location = new System.Drawing.Point(46, 257);
            this.btnSearch_No.Name = "btnSearch_No";
            this.btnSearch_No.Size = new System.Drawing.Size(332, 40);
            this.btnSearch_No.TabIndex = 5;
            this.btnSearch_No.Text = "مشاهده اطلاعات شخصی بر حسب شماره عضویت\r\n";
            this.btnSearch_No.UseVisualStyleBackColor = true;
            this.btnSearch_No.Click += new System.EventHandler(this.btnSearch_No_Click);
            // 
            // btnSearch_Family
            // 
            this.btnSearch_Family.Font = new System.Drawing.Font("B Davat", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(178)));
            this.btnSearch_Family.Location = new System.Drawing.Point(46, 303);
            this.btnSearch_Family.Name = "btnSearch_Family";
            this.btnSearch_Family.Size = new System.Drawing.Size(332, 40);
            this.btnSearch_Family.TabIndex = 7;
            this.btnSearch_Family.Text = "مشاهده اطلاعات شخصی بر حسب نام خانوادگی\r\n";
            this.btnSearch_Family.UseVisualStyleBackColor = true;
            this.btnSearch_Family.Click += new System.EventHandler(this.btnSearch_Family_Click);
            // 
            // frmMain
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.ClientSize = new System.Drawing.Size(425, 375);
            this.Controls.Add(this.btnSearch_Family);
            this.Controls.Add(this.btnSearch_No);
            this.Controls.Add(this.btnList);
            this.Controls.Add(this.btnEdit);
            this.Controls.Add(this.btnExtend);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.btnEnroll);
            this.MaximizeBox = false;
            this.Name = "frmMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Main";
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.frmMain_FormClosed);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnEnroll;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnExtend;
        private System.Windows.Forms.Button btnEdit;
        private System.Windows.Forms.Button btnList;
        private System.Windows.Forms.Button btnSearch_No;
        private System.Windows.Forms.Button btnSearch_Family;

    }
}

