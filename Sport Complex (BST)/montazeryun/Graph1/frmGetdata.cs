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
    public partial class frmGetdata : Form
    {
        public frmGetdata()
        {
            InitializeComponent();
        }
        
        UInt64 ID;
        public frmGetdata(UInt64 id)
        {
            InitializeComponent();
            ID = id;
        }

        SportsmanNode sp;
        public frmGetdata(SportsmanNode s)
        {
            InitializeComponent();
            sp = s;
            ShowData();
        }
        
        Byte MounthCredit;
        Boolean f = false, v = false, w = false, t = false, s = false;

        private void btnEnrolling_Click(object sender, EventArgs e)
        {
            
            if (chbFootball.Checked)
            {
                f=true;
            }
             if (chbValyball.Checked)
            {
                v=true;
            }
             if (chbWrestle.Checked)
            {
                w=true;
            }
             if (chbTekvando.Checked)
            {
                t=true;
            }
             if (chbSwiming.Checked)
            {
                s=true;
            }

            MounthCredit = Convert.ToByte(Convert.ToUInt16(cmbCreditAccount.Text) / 1000);

            if (StaticData.Operate != "Edit")
            {
                InitializeObject(StaticData.IDNo++);
                if (StaticData.bst.Insert())
                {
                    MessageBox.Show("Enrolling completed sucssefully.\nYour ID is ' "+(StaticData.IDNo-1).ToString()+
                                                       " '.\nYour credit extended erenow  "+StaticData.temp.creditDate , "Registerd");
                }
                else
                {
                    MessageBox.Show("This ID already exist in list!", "No Register");
                }
            } //end enroll
            else
            {
                InitializeObject(ID);
            } //end edit
            this.Close();
        }

        private void ShowData()
        {
            txtName.Text = sp.name;
            txtFamily.Text = sp.family;
            txtFatherName.Text = sp.fatherName;
            mskBirthCertificateNo.Text = sp.birthCertificateNo.ToString();
            mskNationalNo.Text = sp.nationalNo.ToString();
            mskMembershipDate.Text = sp.membershipDate;
            mskBirthYear.Text = sp.birthYear.ToString();
            cmbCreditAccount.Text = sp.credit.ToString();
            if (sp.football)
            {
                chbFootball.Checked = true;
            }
            if (sp.valyball)
            {
                chbValyball.Checked = true;
            }
            if (sp.wrestle)
            {
                chbWrestle.Checked = true;
            }
            if (sp.tekvando)
            {
                chbTekvando.Checked = true;
            }
            if (sp.swiming)
            {
                chbSwiming.Checked = true;
            }
            btnEnrolling.Enabled = false;
            lblCreditDate.Visible = true;
            mskCreditDate.Visible = true;
            mskCreditDate.Text = sp.creditDate;

        } //end ShowData()

        private void InitializeObject(UInt64 IDInsert)
        {
            StaticData.temp.name = txtName.Text;
            StaticData.temp.family = txtFamily.Text;
            StaticData.temp.fatherName = txtFatherName.Text;
            StaticData.temp.membershipDate = mskMembershipDate.Text;
            Date creditClass = new Date(mskMembershipDate.Text);
            creditClass.IncreaseBalance(MounthCredit);
            StaticData.temp.creditDate = creditClass.CreditDateStr();
            StaticData.temp.credit = Convert.ToUInt32(cmbCreditAccount.Text);
            StaticData.temp.birthCertificateNo = Convert.ToUInt64(mskBirthCertificateNo.Text);
            StaticData.temp.nationalNo = Convert.ToUInt64(mskNationalNo.Text);
            StaticData.temp.id = IDInsert;
            StaticData.temp.birthYear = Convert.ToUInt16(mskBirthYear.Text);
            StaticData.temp.mounthIncrease = MounthCredit;
            StaticData.temp.football = f;
            StaticData.temp.valyball = v;
            StaticData.temp.wrestle = w;
            StaticData.temp.tekvando = t;
            StaticData.temp.swiming = s;
            StaticData.temp.left = StaticData.temp.right = null;
        }

    }
}
