using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Graph1
{
    public partial class frmExtend : Form
    {
        public frmExtend()
        {
            InitializeComponent();
            txtMembershipNo.Focus();
        }

        private void btnExtend_Click(object sender, EventArgs e)
        {
            Byte inc = Convert.ToByte(Convert.ToUInt16(cmbCreditAccount.Text) / 1000);
            SportsmanNode item = new SportsmanNode();
            item = StaticData.bst.Search(Convert.ToUInt64(txtMembershipNo.Text));
            if (item == null) 
            {
                MessageBox.Show("This IDNO not exist in list. Please enter Id again.", "Not Found");
                txtMembershipNo.Text = "";
                txtMembershipNo.Focus();
            }
            else
            {
                Date creditClass = new Date(item.membershipDate);
                creditClass.IncreaseBalance(inc);
                item.creditDate = creditClass.CreditDateStr();
                MessageBox.Show("Your credit extended erenow  " + item.creditDate + "  ", "Extend");
            }
            
        }

        private void frmExtend_Load(object sender, EventArgs e)
        {
            txtMembershipNo.Focus();
        }

        private void txtMembershipNo_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar < '0' || e.KeyChar > '9') && Convert.ToInt16(e.KeyChar) != 8 && e.KeyChar != '.' && e.KeyChar != '-')
            {
                e.Handled = true;
            }
        }
    }
}
