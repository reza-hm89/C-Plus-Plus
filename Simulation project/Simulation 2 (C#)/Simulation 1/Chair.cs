using System;
using System.Collections.Generic;
using System.Text;

namespace Simulation_1
{
    class Chair
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
