using System;
using System.Collections.Generic;
using System.Text;

namespace Simulation_1
{
    class Consumer
    {
        public int begintime, servicetime, waittime;
        public Boolean serviced;

        public Consumer()
        {
            begintime = waittime = servicetime = 0;
            serviced = false;
        }
    }
}
