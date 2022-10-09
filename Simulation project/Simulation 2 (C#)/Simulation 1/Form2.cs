using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Simulation_1
{
    public partial class Form2 : Form
    {
        timeline []time;

        public Form2()
        {
            InitializeComponent();
        }
        public Form2 (timeline[] t,int n)
        {
            time=t;
            InitializeComponent();
            for (int i = 0; i < n; i++)
            {
                label5.Text += time[i].time.ToString()+"\n";
                label6.Text += time[i].consumer.ToString() + "\n";
                label7.Text += time[i].events.ToString() + "\n";
            }
        }
    }
}
