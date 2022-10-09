using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Graph1
{
    class StaticData
    {
        static internal BST bst = new BST();
        static internal UInt64 IDNo = 1100;
        static internal UInt32 Cntr = 0;
        static internal UInt64 IDFound = 0;
        static internal String Operate; //Edit or Delete Node
        static public Sport temp = new Sport();
    }

    public class Date
    {
        private UInt16 Year, Mounth, Day;
        private String DateStr;

        public Date(String s)
        {
            DateStr = s;
            ConvertDate();
        }

        public UInt16 year
        {
            get
            {
                return Year;
            }
            set
            {
                Year = value;
            }
        }

        public UInt16 mounth
        {
            get
            {
                return Mounth;
            }
            set
            {
                Mounth = value;
            }
        }

        public UInt16 day
        {
            get
            {
                return Day;
            }
            set
            {
                Day = value;
            }
        }

        public void ConvertDate()
        {
            String y="    ", m="  ", d="  ";
            Byte i, j;
            for(i = 0, j=0 ; i < 4; i++,j++)
            {
                y = y.Remove(j, 1);
                y = y.Insert(j, DateStr[i].ToString());
            }
            year = Convert.ToUInt16(y);
            
            for (i=5, j=0 ; i < 7; i++,j++)
            {
                m = m.Remove(j, 1);
                m = m.Insert(j, DateStr[i].ToString());
            }
            mounth = Convert.ToUInt16(m);

            for (i = 8, j=0 ; i < 10; i++,j++)
            {
                d = d.Remove(j, 1);
                d = d.Insert(j, DateStr[i].ToString());
            }
            day = Convert.ToUInt16(d);
        }

        public void IncreaseBalance(UInt16 balance)
        {
            balance += mounth;
            if (balance > 12)
            {
                balance -= 12;
                mounth = balance;
                ++year;
            }
            else mounth = balance;
        }

        public String CreditDateStr()
        {
            String s = " ";
            s = s.Insert(0, year.ToString());
            s = s.Insert(4, "/");
            s = s.Insert(5, mounth.ToString());
            s = s.Insert(7, "/");
            s = s.Insert(8, day.ToString());
            return s;
        }

    } //end class Date
}
