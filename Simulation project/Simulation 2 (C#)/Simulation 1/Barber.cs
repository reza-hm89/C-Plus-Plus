using System;
using System.Collections.Generic;
using System.Text;

namespace Simulation_1
{
    public class Barber
    {
        public Boolean busy;
        public int freetime, busytime, totalbusytime, getstart;
        public byte numofconsumer;

        public Barber()
        {
            busy = false;
            freetime = busytime = totalbusytime = getstart = numofconsumer = 0;
        }
    }
}
