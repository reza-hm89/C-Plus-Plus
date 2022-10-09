using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Graph1
{
    public class Sport
    {
        private String Name;
        private String Family;
        private String FatherName;
        private String MemberShipDate;
        private String CreditDate;
        private UInt32 Credit;
        private UInt64 BirthCertificateNo;
        private UInt64 NationalNo;
        private UInt64 ID;
        private UInt16 BirthYear;
        private Byte MounthIncrease;
        private Boolean Football;
        private Boolean Valyball;
        private Boolean Wrestle;
        private Boolean Tekvando;
        private Boolean Swiming;
        private SportsmanNode Left, Right;

        public Sport()
        {
            Left = Right = null;
        }

        public String name
        {
            get
            {
                return Name;
            }
            set
            {
                Name = value;
            }
        }

        public String family
        {
            get
            {
                return Family;
            }
            set
            {
                Family = value;
            }
        }

        public String fatherName
        {
            get
            {
                return FatherName;
            }
            set
            {
                FatherName = value;
            }
        }

        public String membershipDate
        {
            get
            {
                return MemberShipDate;
            }
            set
            {
                MemberShipDate = value;
            }
        }

        public String creditDate
        {
            get
            {
                return CreditDate;
            }
            set
            {
                CreditDate = value;
            }
        }

        public UInt32 credit
        {
            get
            {
                return Credit;
            }
            set
            {
                Credit = value;
            }
        }

        public UInt64 birthCertificateNo
        {
            get
            {
                return BirthCertificateNo;
            }
            set
            {
                BirthCertificateNo = value;
            }
        }

        public UInt64 nationalNo
        {
            get
            {
                return NationalNo;
            }
            set
            {
                NationalNo = value;
            }
        }

        public UInt64 id
        {
            get
            {
                return ID;
            }
            set
            {
                ID = value;
            }
        }

        public UInt16 birthYear
        {
            get
            {
                return BirthYear;
            }
            set
            {
                BirthYear = value;
            }
        }

        public Byte mounthIncrease
        {
            get
            {
                return MounthIncrease;
            }
            set
            {
                MounthIncrease = value;
            }
        }

        public Boolean football
        {
            get
            {
                return Football;
            }
            set
            {
                Football = value;
            }
        }

        public Boolean valyball
        {
            get
            {
                return Valyball;
            }
            set
            {
                Valyball = value;
            }
        }

        public Boolean wrestle
        {
            get
            {
                return Wrestle;
            }
            set
            {
                Wrestle = value;
            }
        }

        public Boolean tekvando
        {
            get
            {
                return Tekvando;
            }
            set
            {
                Tekvando = value;
            }
        }

        public Boolean swiming
        {
            get
            {
                return Swiming;
            }
            set
            {
                Swiming = value;
            }
        }

        public SportsmanNode left
        {
            get
            {
                return Left;
            }
            set
            {
                Left = value;
            }
        }

        public SportsmanNode right
        {
            get
            {
                return Right;
            }
            set
            {
                Right = value;
            }
        }

    } //end of Sport class

}
