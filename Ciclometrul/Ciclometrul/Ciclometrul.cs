using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Ciclometrul
{
    [TestClass]
    public class Ciclometrul
    {
        //**********************************************Tests******************************************

        //**********************************************Distance Test******************************************
        [TestMethod]
        public void DistanceTest()
        {
            var competitor1 = new CompetitorStruct(new int[] { 9,2,6,3,8 }, 1, "Popescu");
            var competitor2 = new CompetitorStruct(new int[] { 8,6,7,1,3 }, 2, "Ionescu");
            var competitor3 = new CompetitorStruct(new int[] { 9,6,5,2,2 }, 3, "Daniel");
            var competitor4 = new CompetitorStruct(new int[] { 10,5,1,3,10 }, 4, "Grigore");
            var competitor5 = new CompetitorStruct(new int[] {4,8,9,8,11 }, 5, "Adrian");

            CompetitorStruct[] contender = new CompetitorStruct[] {competitor1,competitor2,competitor3,competitor4,competitor5};
 
            int[] result = { 56, 50, 48, 58, 80 };
           CollectionAssert.AreEqual(result, Distance(contender));
        }
        //**********************************************Distance Test******************************************
        [TestMethod]
        public void MaxSpeedTest()
        {
            var competitor1 = new CompetitorStruct(new int[] { 9, 2, 6, 3, 8 }, 1, "Popescu");
            var competitor2 = new CompetitorStruct(new int[] { 8, 6, 7, 1, 3 }, 2, "Ionescu");
            var competitor3 = new CompetitorStruct(new int[] { 9, 6, 5, 2, 2 }, 3, "Daniel");
            var competitor4 = new CompetitorStruct(new int[] { 10, 5, 1, 3, 10 }, 4, "Grigore");
            var competitor5 = new CompetitorStruct(new int[] { 4, 8, 9, 8, 11 }, 5, "Adrian");

            CompetitorStruct[] contender = new CompetitorStruct[] { competitor1, competitor2, competitor3, competitor4, competitor5 };

            string[] result = {"5","Adrian"};
            CollectionAssert.AreEqual(result, MaxSpeedName(contender));
        }

        //**********************************************Declaration******************************************

        //**************************************Competitor struct***********************************************
        struct CompetitorStruct
        {
            public int[] rotations;
            public int startNumber;
            public string name;
            public int lengthRoata;

            public CompetitorStruct(int[] rotations, int startNumber, string name)
            {
                this.rotations = rotations;
                this.startNumber = startNumber;
                this.name = name;
                this.lengthRoata = 2;
            }
        
         }
        //*******************************************Distance calculation*******************************************
        int[] Distance(CompetitorStruct[] Competitor){
            var result = new int[5];
            for (int i = 0; i < 5; i++)
            {
                foreach(int rot in Competitor[i].rotations)
                {
                    result[i] += Competitor[i].lengthRoata * rot;
                }
               
            }
            return result;
    }
        //*********************************************Max speed******************************************************
        string[] MaxSpeedName(CompetitorStruct[] Competitor)
        {
            int MaxSpeed=0;
            string MaxSpeedPosition="",Name="";
            for (int i = 0; i < 5; i++)
            {
                var temp = 1;
                foreach (int rot in Competitor[i].rotations)
                {
                    if (rot > MaxSpeed)
                    {
                        MaxSpeedPosition = temp.ToString();
                        Name = Competitor[i].name;
                    }
                    temp++;
                }
            }
            return new string[] {MaxSpeedPosition,Name};
        }

        //*********************************************Average speed top**********************************************

        //*********************************************Distance top***************************************************

    }
}
