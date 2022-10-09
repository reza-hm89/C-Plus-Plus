using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Graph1
{
    public class SportsmanNode
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

        public SportsmanNode()
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
    } //end of Sportsman class
 
    //**************************************************************************
    //**************************************************************************

    public class BST
    {
        private SportsmanNode root;

        public BST()
        {
            root = null;
        }

        public SportsmanNode RootNode
        {
            get
            {
                return root;
            }
            set
            {
                root = value;
            }
        }

        public Boolean Insert()
        {
            SportsmanNode p, q;
            p = StaticData.bst.root;
            q = null;
            while (p != null)
            {
                q = p;
                if (p.id == StaticData.temp.id)
                {
                    return false;
                }
                else if (p.id < StaticData.temp.id)
                {
                    p = p.right;
                }
                else
                {
                    p = p.left;
                }
            } //end while

            p = new SportsmanNode();
            //Initialize Object p
            p.name = StaticData.temp.name;
            p.family = StaticData.temp.family;
            p.fatherName = StaticData.temp.fatherName;
            p.membershipDate = StaticData.temp.membershipDate;
            p.creditDate = StaticData.temp.creditDate;
            p.credit = StaticData.temp.credit;
            p.birthCertificateNo = StaticData.temp.birthCertificateNo;
            p.nationalNo = StaticData.temp.nationalNo;
            p.birthYear = StaticData.temp.birthYear;
            p.id = StaticData.temp.id;
            p.football = StaticData.temp.football;
            p.valyball = StaticData.temp.valyball;
            p.wrestle = StaticData.temp.wrestle;
            p.tekvando = StaticData.temp.tekvando;
            p.swiming = StaticData.temp.swiming;
           
            StaticData.Cntr++;

            if (root == null)
            {
               root = p;
            }

            else
            {
                if (q.id < StaticData.temp.id)
                {
                    q.right = p;
                }
                else
                {
                    q.left = p;
                }
            }
            return true;
        } // end Insert()

        public Boolean Remove(UInt64 ID)
        {
            Boolean found = false;
            SportsmanNode p, q;
            p = root;
            q = null;
            q = p;
            while (!found) 
            {
                if (p.id == ID)
                {
                    found = true;
                }
                else if (p.id < ID)
                {
                    q = p;
                    p = p.right;
                }
                else
                {
                    q = p;
                    p = p.left;
                }
                if (p == null)
                {
                    break;
                }
            } //end while

            if (found)
            {
                if (q != p && p.left == null && p.right == null) //this is a leaf node.
                {
                    if (q.left == p)
                    {
                        q.left = null;
                    }
                    else
                    {
                        q.right = null;
                    }
                } //end of if leaf node 
                else if (q != p && p.left == null || p.right == null) // this node has one child.
                {
                    if (q.right == p)
                    {
                        q.right = p.right;
                    }
                    else
                    {
                        q.left = p.left;
                    }
                } //end of else if one child
                else //this node has two child.
                {
                    SportsmanNode n = p.left;
                    if (n != null)
                    {
                        while (n.right != null)
                        {
                            n = n.right;
                        }
                    }
                    if (q == p)
                    {
                        if (n == null)
                        {
                            q = q.right;
                            root = q;
                        }
                        q = n;
                    }
                    else
                    {
                        if (q.left == p)
                        {
                            q.left = n;
                        }
                        else
                        {
                            q.right = n;
                        }
                    }
                } //end of else
                StaticData.Cntr--;
                return true;
            } // end of if found
            return false;
        } // end of Remove()

        public SportsmanNode Search(UInt64 ID)
        {
            SportsmanNode p = root;
            while (p != null)
            {
                if (p.id == ID)
                {
                    return p;
                }
                if (p.id < ID)
                {
                    p = p.right;
                }
                else
                {
                    p = p.left;
                }
            }
            return null;
        } //end of Search()

        public SportsmanNode FamilySearch(SportsmanNode curRoot, String Family)
        {
            if (curRoot != null)
            {
                FamilySearch(curRoot.left, Family);
                if (curRoot.family == Family) 
                {
                    StaticData.IDFound = curRoot.id;
                    return curRoot;
                }
                FamilySearch(curRoot.right, Family);
            }
            return null;
        }

    } //end of BST class
}
