using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Simulation_1
{
    struct timeline
    {
        public int time,consumer;
        public string events;
    };

    public partial class Form1 : Form
    {
        public int numofconsumer, numofstylist, numofchair, service, begin, cnt,outofservice;
        int time,k;
        timeline[] t=new timeline[100];    
        Consumer[] c;
        Stylist[] s;
        Chair chair;

        public Form1()
        {
            numofconsumer = numofstylist = numofchair = service = begin = cnt = time = outofservice=k= 0;
            InitializeComponent();
            button3.Enabled = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox4.Enabled = textBox5.Enabled = label5.Enabled = label4.Enabled = label6.Enabled = true;

            numofconsumer = Convert.ToInt32(textBox2.Text);
            numofstylist = Convert.ToInt32(textBox1.Text);
            numofchair = Convert.ToInt32(textBox3.Text);
            c = new Consumer[numofconsumer];
            s = new Stylist[numofstylist];
            for (int i = 0; i < numofconsumer; i++)
            {
                c[i] = new Consumer();
            }
            for (int i = 0; i < numofstylist; i++)
            {
                s[i] = new Stylist();
            }
            chair = new Chair();
            label6.Text = "Consumer " + (cnt + 1) + ":";
            textBox1.Enabled = textBox2.Enabled = textBox3.Enabled = button1.Enabled = false;

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (cnt < numofconsumer)
            {

                begin = Convert.ToInt32(textBox4.Text);
                service = Convert.ToInt32(textBox5.Text);
                textBox4.ResetText();
                textBox5.ResetText();
                c[cnt].begintime = begin;
                c[cnt].servicetime = service;
                cnt++;
                label6.Text = "Consumer " + (cnt + 1) + ":";

            }

            if (cnt >= numofconsumer)
            {
                button2.Enabled = textBox4.Enabled = textBox5.Enabled = false;
                button3.Enabled = true;
            }
        }
        public void Calculate()
        {
            int chairs = 0, index;
            Boolean sw = false;
            while (true)
            {
                for (int i = 0; i < numofconsumer; i++)
                {
                    if (time == c[i].begintime)
                    {
                        sw = false;
                        for (int j = 0; j < numofstylist; j++)
                        {
                            if (s[j].busy == false && c[i].serviced == false)
                            {
                                sw = true;
                                c[i].serviced = true;
                                s[j].busy = true;
                                s[j].getstart = time;
                                s[j].busytime = c[i].servicetime;
                                s[j].numofconsumer++;
                                s[j].totalbusytime += s[j].busytime;
                                t[k].events = "start to service";
                                t[k].time = time;
                                t[k++].consumer = i;
                            }
                        }
                    }
                    if (time >= c[i].begintime && sw == false )//&& chairs < numofchair)
                    {
                        chair.Add(i);
                        chairs++;
                        t[k].events = "enter to queue";
                        t[k].time = time;
                        t[k++].consumer = i;
                    }
                    
                    if (time >= c[i].begintime && c[i].serviced == false)
                    {
                        c[i].waittime++;
                    }
                }
                for (int i = 0; i < numofstylist; i++)
                {
                    if (time == (s[i].getstart + s[i].busytime))
                    {
                        s[i].busy = false;
                        if (chairs > 0)
                        {
                            index = chair.Del();
                            c[index].serviced = true;
                            s[i].busy = true;
                            s[i].getstart = time;
                            s[i].busytime = c[index].servicetime;
                            s[i].numofconsumer++;
                            s[i].totalbusytime += s[i].busytime;
                            chairs--;
                            t[k].events = "delete from queue";
                            t[k].time = time;
                            t[k++].consumer = index;
                        }

                    }
                    if (s[i].busy == false)
                    {
                        s[i].freetime++;
                    }
                }
                sw = false;
                for (int i = 0; i < numofconsumer; i++)
                {
                    if (c[i].serviced == false)
                    {
                        sw = true;
                    }
                }
                if (sw == false)
                {
                    for (int j = 0; j < numofstylist; j++)
                    {
                        if (s[j].busy == true)
                        {
                            sw = true;
                        }
                    }
                }
                if (sw == false)
                {
                    break;
                }
                time++;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Calculate();
            label7.Text += time.ToString();
            float avg = 0;
            for (int i = 0; i < numofconsumer; i++)
            {
                label8.Text += "\nConsumer" + (i + 1) + " waiting time: " + c[i].waittime;
                avg += c[i].waittime;
            }
            for (int i = 0; i < numofstylist; i++)
            {
                label9.Text += "\nStylist" + (i + 1) + " free time: " + s[i].freetime + "   " + "Number of serviced: " + s[i].numofconsumer;
            }
            label10.Text += (avg / numofconsumer).ToString();
            label11.Text += outofservice.ToString();

            for (int i = 0; i < k; i++)
            {
                label15.Text += t[i].events + "       " + t[i].time + "       " + t[i].consumer + "\n";
            }
        }
    }

    public class Stylist
    {
        public Boolean busy;
        public int freetime, busytime, totalbusytime, getstart;
        public byte numofconsumer;

        public Stylist()
        {
            busy = false;
            freetime = busytime = totalbusytime = getstart = numofconsumer = 0;
        }
    }

    public class Consumer
    {
        public int begintime, servicetime, waittime;
        public Boolean serviced;

        public Consumer()
        {
            begintime = waittime = servicetime = 0;
            serviced = false;
        }
    }
    public class Chair
    {
        Queue<int> chair;
        public Chair()
        {
            chair = new Queue<int>();
        }

        public void Add(int index)
        {
            chair.Enqueue(index);
        }

        public int Del()
        {
            return chair.Dequeue();
        }

        public int Show()
        {
            return chair.Peek();
        }

    }
}