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
        //***************************************QuickSort Test**********************************************
        [TestMethod]
        public void QuickSortTest()
        {
            int[] list = new int[] { 6, 8, 18, 3, 22, 19, 58, 10 };
            int[] sortlist = new int[] { 3, 6, 8, 10, 18, 19, 22, 58 };
           // Assert.AreEqual(3, SplitList(list, 0, list.Length - 1));
           QuickSort(list, 0, list.Length-1);
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
            int[] averageSpeed = new int[] { };
            
            for (int i = 0; i < competitor.Length; i++)
            {
                averageSpeed[i] = competitor[i].averageSpeed;
            }
            return averageSpeed;
            
        }
        //*********************************************Distance top***************************************************

        Competitor[] SortbyProperty(Competitor[] competitor,int first,int last, string criteria,string typeOfSort)
        {
            Competitor tempCompetitor;
            return competitor;

        }
        int SplitList(int[] list,int first,int last)
        {
            int pivot = list[last];
            int pivotPosition = first;
            int temp=0,i;
            for ( i = first; i < last; i++)
            {
                if (list[i] <= pivot)
                {
                    temp = list[i];
                    list[i] = list[pivotPosition];
                    list[pivotPosition] =temp;
                    pivotPosition++;
                }   
            }
            temp = list[i];
            list[i] = list[pivotPosition];
            list[pivotPosition] = temp;
            return pivotPosition;
        }
        public void QuickSort(int[] list, int first,int last)
        {
            
            int positionPivot = SplitList(list, first, last);
            if (positionPivot > first)  QuickSort(list, first, positionPivot - 1); 
            if (positionPivot < last)  QuickSort(list, positionPivot + 1 ,last); 
       
           
        }
   
    }
}
