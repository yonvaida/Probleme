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
            var competitor1 = new Competitor(new int[] { 9,2,6,3,8 }, 1, "Popescu",2);
            var competitor2 = new Competitor(new int[] { 8,6,7,1,3 }, 2, "Ionescu",2);
            var competitor3 = new Competitor(new int[] { 9,6,5,2,2 }, 3, "Daniel",2);
            var competitor4 = new Competitor(new int[] { 10,5,1,3,10 }, 4, "Grigore",2);
            var competitor5 = new Competitor(new int[] {4,8,9,8,11 }, 5, "Adrian",2);

            Competitor[] contender = new Competitor[] {competitor1,competitor2,competitor3,competitor4,competitor5};
 
            int[] result = { 56, 50, 48, 58, 80 };
           CollectionAssert.AreEqual(result, Distance(contender));
        }
        //**********************************************Distance Test******************************************
        [TestMethod]
        public void MaxSpeedTest()
        {
            var competitor1 = new Competitor(new int[] { 9, 2, 6, 3, 8 }, 1, "Popescu",2);
            var competitor2 = new Competitor(new int[] { 8, 6, 7, 1, 3 }, 2, "Ionescu",2);
            var competitor3 = new Competitor(new int[] { 9, 6, 5, 2, 2 }, 3, "Daniel",2);
            var competitor4 = new Competitor(new int[] { 10, 5, 1, 3, 10 }, 4, "Grigore",2);
            var competitor5 = new Competitor(new int[] { 4, 8, 9, 8, 11 }, 5, "Adrian",2);

            Competitor[] contender = new Competitor[] { competitor1, competitor2, competitor3, competitor4, competitor5 };

            string[] result = {"5","Adrian"};
            CollectionAssert.AreEqual(result, MaxSpeedName(contender));
        }

        //**********************************************Declaration******************************************

        //**************************************Competitor struct***********************************************
        struct Competitor
        {
            public int[] rotations;
            public string name;
            public int startNumber;
            public int lengthWheel;
            public int distance;
            public int maxSpeed;
            public int averageSpeed;
            public Competitor(int[] rotations, int startNumber, string name,int lengthWheel)
            {
                this.rotations = rotations;
                this.startNumber = startNumber;
                this.name = name;
                this.lengthWheel = lengthWheel;
                this.averageSpeed = 0;
                this.distance = 0;
                this.maxSpeed = 0;

                for(int i = 0; i < rotations.Length; i++)
                {
                    this.maxSpeed = maxSpeed < rotations[i] ? rotations[i] : maxSpeed;
                    this.averageSpeed += rotations[i];
                    this.distance += rotations[i] * this.lengthWheel;
                }
                this.averageSpeed = this.averageSpeed / rotations.Length;
            }
        
         }
        //*******************************************Distance calculation*******************************************
        int[] Distance(Competitor[] competitor){
            var result = new int[competitor.Length];
            for (int i = 0; i < competitor.Length; i++)
            {
                result[i] = competitor[i].distance;
               
            }
            return result;
    }
        //*********************************************Max speed******************************************************
        string[] MaxSpeedName(Competitor[] competitor)
        {
            int MaxSpeed=0;
            string MaxSpeedPosition="",Name="";
            for (int i = 0; i < competitor.Length; i++)
            {
                var temp = 1;
                foreach (int rot in competitor[i].rotations)
                {
                    if (rot > MaxSpeed)
                    {
                        MaxSpeedPosition = temp.ToString();
                        Name = competitor[i].name;
                    }
                    temp++;
                }
            }
            return new string[] {MaxSpeedPosition,Name};
        }

        //*********************************************Average speed top**********************************************
        int[] AverageSpeedTop(Competitor[] competitor)
        {
            for(int i = 0; i < competitor.Length; i++)
            {
                AverageSpeedTop[i]
            }
        }
        //*********************************************Distance top***************************************************

        Competitor[] SortbyProperty(Competitor[] competitor, string criteria)
        {
            Competitor tempCompetitor;

        }
    }
}
