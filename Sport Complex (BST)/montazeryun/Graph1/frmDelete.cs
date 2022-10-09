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
    public partial class frmSearch : Form
    {
        String SearchType;
        public frmSearch(String s)
        {
            InitializeComponent();
            SearchType = s;
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            if (SearchType == "Text")
            {
                
                SportsmanNode sp = new SportsmanNode();
                sp = StaticData.bst.FamilySearch(StaticData.bst.RootNode, txtFamily.Text);
                if (StaticData.IDFound != 0)
                {
                    sp = StaticData.bst.Search(StaticData.IDFound);
                    frmGetdata Get = new frmGetdata(sp);
                    Get.ShowDialog();
                    StaticData.IDFound = 0;
                }
                else
                {
                    MessageBox.Show("This Family not exist in list!", "Not found");
                }
                
            }
            else
            {
                if (txtMembershipNo.Text != null)
                {
                    if (StaticData.Operate == "Delete")
                    {
                        if (StaticData.bst.Remove(Convert.ToUInt64(txtMembershipNo.Text)))
                        {
                            MessageBox.Show("Removing perfomed successfully.");
                        }
                        else
                        {
                            MessageBox.Show("This ID Not exist in the list.");
                        }
                    } // end Delete
                    else if (StaticData.Operate == "Edit") //for Edit form
                    {
                        SportsmanNode item = new SportsmanNode();
                        item = StaticData.bst.Search(Convert.ToUInt64(txtMembershipNo.Text));
                        if (item == null)
                        {
                            MessageBox.Show("This IDNO not exist in list. Please enter ID again.", "Not Found");
                            txtMembershipNo.Text = "";
                            txtMembershipNo.Focus();
                        }
                        else
                        {

                            frmGetdata Get = new frmGetdata(item);
                            Get.ShowDialog();
                            //initialize Object
                            item.name = StaticData.temp.name;
                            item.family = StaticData.temp.family;
                            item.fatherName = StaticData.temp.fatherName;
                            item.membershipDate = StaticData.temp.membershipDate;
                            item.creditDate = StaticData.temp.creditDate;
                            item.credit = StaticData.temp.credit;
                            item.birthCertificateNo = StaticData.temp.birthCertificateNo;
                            item.nationalNo = StaticData.temp.nationalNo;
                            item.birthYear = StaticData.temp.birthYear;
                            item.mounthIncrease = StaticData.temp.mounthIncrease;
                            item.football = StaticData.temp.football;
                            item.valyball = StaticData.temp.valyball;
                            item.wrestle = StaticData.temp.wrestle;
                            item.tekvando = StaticData.temp.tekvando;
                            item.swiming = StaticData.temp.swiming;

                            MessageBox.Show("Editing performed sucssesfully.", "Registered");
                        }
                    }//end Edit form
                    else //search form
                    {
                        SportsmanNode sp = new SportsmanNode();
                        sp = StaticData.bst.Search(Convert.ToUInt64(txtMembershipNo.Text));
                        if (sp == null)
                        {
                            MessageBox.Show("This IDNO not exist in list. Please enter ID again.", "Not Found");
                            txtMembershipNo.Text = "";
                            txtMembershipNo.Focus();
                        }
                        else
                        {
                            frmGetdata Get = new frmGetdata(sp);
                            Get.ShowDialog();
                        }
                    }
                }
            }//end else (this Number)
            this.Close();
        }

        private void txtMembershipNo_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar < '0' || e.KeyChar > '9') && Convert.ToInt16(e.KeyChar) != 8 && e.KeyChar != '.' && e.KeyChar != '-')
            {
                e.Handled = true;
            }
        }

        private void frmSearch_Load(object sender, EventArgs e)
        {
            if (SearchType == "Number")
            {
                txtFamily.Visible = false;
            }
            else //Family Search (Text)
            {
                txtMembershipNo.Visible = false;
                lblMembershipNo.Text = "نام خانوادگی :";
            }
            
            if (StaticData.Operate == "Edit") 
            {
                this.Text = "Edit";
            }
            else
            {
                this.Text = "Delete";
            }
        }
    }
}
