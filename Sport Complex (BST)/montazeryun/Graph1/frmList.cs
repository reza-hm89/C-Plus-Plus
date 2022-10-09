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
    public partial class frmList : Form
    {
        String ListType, OPSport;
        UInt32 i = 1;

        public frmList()
        {
            InitializeComponent();
        }
        
        private void inOrderListAll(SportsmanNode sp)
        {
            if (sp != null)
            {
                inOrderListAll(sp.left);
                ShowData(sp);
                inOrderListAll(sp.right);
            }
        } //inOrderListAll()

        private void inOrderSpecialList(SportsmanNode sp)
        {
            if (sp != null) 
            {
                inOrderSpecialList(sp.left);
                if (MemberShipCheck(sp))
                {
                    ShowData(sp);
                }
                inOrderSpecialList(sp.right);
            }
        } //end inOrderSpecialList()

        private Boolean MemberShipCheck(SportsmanNode sp)
        {
            switch (OPSport)
            {
                case "football":
                    if (sp.football)
                    {
                        return true;
                    }
                    return false;
                case"valyball":
                    if (sp.valyball)
                    {
                        return true;
                    }
                    return false;
                case"wrestle":
                    if (sp.wrestle)
                    {
                        return true;
                    }
                    return false;
                case"tekvando":
                    if (sp.tekvando)
                    {
                        return true;
                    }
                    return false;
                case"swiming":
                    if (sp.swiming)
                    {
                        return true;
                    }
                    return false;
            } //end switch
            return false;
        } //end MemberShipCheck()

        private void ShowData(SportsmanNode sp)
        {
            rtbRow.Text = rtbRow.Text + "\r" + i++.ToString();
            rtbName.Text = rtbName.Text + "\r" + sp.name;
            rtbFamily.Text = rtbFamily.Text + "\r" + sp.family;
            rtdFatherName.Text = rtdFatherName.Text + "\r" + sp.fatherName;
            rtbCertificateNo.Text = rtbCertificateNo.Text + "\r" + sp.birthCertificateNo.ToString();
            rtdNationalNo.Text = rtdNationalNo.Text + "\r" + sp.nationalNo.ToString();
            rtdBirthYear.Text = rtdBirthYear.Text + "\r" + sp.birthYear.ToString();
            rtbMemberDate.Text = rtbMemberDate.Text + "\r" + sp.membershipDate;
            rtdCreditDate.Text = rtdCreditDate.Text + "\r" + sp.creditDate;
            rtbID.Text = rtbID.Text + "\r" + sp.id.ToString();
        } //end ShowData()

        private void frmList_Load(object sender, EventArgs e)
        {
            LoadData();
        }

        private void LoadData()
        {
            ClearData();
            if (ListType == "ListAll")
            {
                inOrderListAll(StaticData.bst.RootNode);
            }
            else
            {
                inOrderSpecialList(StaticData.bst.RootNode);
            }
        }

        private void ClearData()
        {
            rtbRow.Text = "";
            rtbName.Text = "";
            rtbFamily.Text = "";
            rtdFatherName.Text = "";
            rtbCertificateNo.Text = "";
            rtbID.Text = "";
            rtbMemberDate.Text = "";
            rtdBirthYear.Text = "";
            rtdNationalNo.Text = "";
            rtdCreditDate.Text = "";
            i = 1;
        }
        
        private void rdbFootball_CheckedChanged(object sender, EventArgs e)
        {
            OPSport = "football";
            ListType = "ListSpecial";
            LoadData();
        }

        private void rdbVallyball_CheckedChanged(object sender, EventArgs e)
        {
            OPSport = "valyball";
            ListType = "ListSpecial";
            LoadData();
        }

        private void rdbWrestle_CheckedChanged(object sender, EventArgs e)
        {
            OPSport = "wrestle";
            ListType = "ListSpecial";
            LoadData();
        }

        private void rdbTekvando_CheckedChanged(object sender, EventArgs e)
        {
            OPSport = "tekvando";
            ListType = "ListSpecial";
            LoadData();
        }

        private void rdbSwiming_CheckedChanged(object sender, EventArgs e)
        {
            OPSport = "swiming";
            ListType = "ListSpecial";
            LoadData();
        }

        private void rdbAllMember_CheckedChanged(object sender, EventArgs e)
        {
            OPSport = "all";
            ListType = "ListAll";
            LoadData();
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            ClearData();
        }
      
    }
}
