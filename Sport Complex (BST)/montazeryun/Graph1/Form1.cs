using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;

namespace Graph1
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private FileStream input = null;
        private FileStream output = null;
        private BinaryWriter binaryOutput;
        private BinaryReader binaryInput;
        private const Int16 SportSize = 197; //197 Byte Sportsman Node
        private const Int16 StaticDataSize = 12; //12 Byte
        Int32 cntr = 0;
        
        private void btnEnroll_Click(object sender, EventArgs e)
        {
            frmGetdata Get = new frmGetdata();
            Get.ShowDialog();
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            StaticData.Operate = "Delete";
            frmSearch Del = new frmSearch("Number");
            Del.ShowDialog();
        }

        private void preorderSave(SportsmanNode CurRoot)
        {
            if (CurRoot != null)
            {
                Save(CurRoot);
                preorderSave(CurRoot.left);
                preorderSave(CurRoot.right);
            }
        }
        
        public void Save(SportsmanNode CurRoot)
        {
            output.Position = cntr++* SportSize;
            binaryOutput.Write(CurRoot.name);
            binaryOutput.Write(CurRoot.family);
            binaryOutput.Write(CurRoot.fatherName);
            binaryOutput.Write(CurRoot.membershipDate);
            binaryOutput.Write(CurRoot.creditDate);
            binaryOutput.Write(CurRoot.credit);
            binaryOutput.Write(CurRoot.birthCertificateNo);
            binaryOutput.Write(CurRoot.nationalNo);
            binaryOutput.Write(CurRoot.id);
            binaryOutput.Write(CurRoot.birthYear);
            binaryOutput.Write(CurRoot.mounthIncrease);
            binaryOutput.Write(CurRoot.football);
            binaryOutput.Write(CurRoot.valyball);
            binaryOutput.Write(CurRoot.wrestle);
            binaryOutput.Write(CurRoot.tekvando);
            binaryOutput.Write(CurRoot.swiming);
           
        } //end Save()

        public void LoadData()
        {
            Sport temp = new Sport();
            
            for (uint i = 0; i < StaticData.Cntr; i++)
            {
                input.Seek(i * SportSize, 0);
                temp.name = binaryInput.ReadString();
                temp.family = binaryInput.ReadString();
                temp.fatherName = binaryInput.ReadString();
                temp.membershipDate = binaryInput.ReadString();
                temp.creditDate = binaryInput.ReadString();
                temp.credit = binaryInput.ReadUInt32();
                temp.birthCertificateNo = binaryInput.ReadUInt64();
                temp.nationalNo = binaryInput.ReadUInt64();
                temp.id = binaryInput.ReadUInt64();
                temp.birthYear = binaryInput.ReadUInt16();
                temp.mounthIncrease=binaryInput.ReadByte();
                temp.football = binaryInput.ReadBoolean();
                temp.valyball = binaryInput.ReadBoolean();
                temp.wrestle = binaryInput.ReadBoolean();
                temp.tekvando = binaryInput.ReadBoolean();
                temp.swiming = binaryInput.ReadBoolean();
                StaticData.temp = temp;
                StaticData.bst.Insert();
                StaticData.Cntr--;
            } //end of for
            input.Close();
        }

        private void frmMain_FormClosed(object sender, FormClosedEventArgs e)
        {
            output = new FileStream("Sport.Rnd", FileMode.OpenOrCreate, FileAccess.Write);
            binaryOutput = new BinaryWriter(output);
            preorderSave(StaticData.bst.RootNode);
            output.Close();
            output = new FileStream("StaticData.Rnd", FileMode.OpenOrCreate, FileAccess.Write);
            binaryOutput = new BinaryWriter(output);
            binaryOutput.Write(StaticData.Cntr);
            binaryOutput.Write(StaticData.IDNo);
            output.Close();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            if (File.Exists("StaticData.Rnd"))
            {
                input = new FileStream("StaticData.Rnd", FileMode.Open, FileAccess.Read);
                if (input.Length != 0) 
                {
                    binaryInput = new BinaryReader(input);
                    StaticData.Cntr = binaryInput.ReadUInt32();
                    StaticData.IDNo = binaryInput.ReadUInt64();
                }
               input.Close();
            }
            
            if (File.Exists("Sport.Rnd"))
            {
                input = new FileStream("Sport.Rnd", FileMode.Open, FileAccess.Read);
                if (input.Length != 0) 
                {
                    binaryInput = new BinaryReader(input);
                    LoadData();
                }
                input.Close();
            }
        }

        private void btnExtend_Click(object sender, EventArgs e)
        {
            frmExtend Extend = new frmExtend();
            Extend.ShowDialog();
        }

        private void btnEdit_Click(object sender, EventArgs e)
        {
            StaticData.Operate = "Edit";
            frmSearch Edit = new frmSearch("Number");
            Edit.ShowDialog();
        }

        private void btnList_Click(object sender, EventArgs e)
        {
            frmList List = new frmList();
            List.ShowDialog();
        }

        private void btnSearch_No_Click(object sender, EventArgs e)
        {
            frmSearch Search = new frmSearch("Number");
            Search.ShowDialog();
        }

        private void btnSearch_Family_Click(object sender, EventArgs e)
        {
            frmSearch Search = new frmSearch("Text");
            Search.ShowDialog();
        }

    }

}
