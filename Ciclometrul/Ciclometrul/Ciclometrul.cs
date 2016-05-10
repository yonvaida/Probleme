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
            /*int[] list = new int[] { 6, 8, 18, 3, 22, 19, 58, 10 };
            int[] sortlist = new int[] { 3, 6, 8, 10, 18, 19, 22, 58 };
           Assert.AreEqual(3, SplitList(list, 0, list.Length - 1));*/
            var competitor1 = new Competitor(new int[] { 9, 2, 6, 3, 8 }, 1, "Popescu", 2);
            var competitor2 = new Competitor(new int[] { 8, 6, 7, 1, 3 }, 2, "Ionescu", 2);
            var competitor3 = new Competitor(new int[] { 9, 6, 5, 2, 2 }, 3, "Daniel", 2);
            var competitor4 = new Competitor(new int[] { 10, 5, 1, 3, 10 }, 4, "Grigore", 2);
            var competitor5 = new Competitor(new int[] { 4, 8, 9, 8, 11 }, 5, "Adrian", 2);

            Competitor[] contender = new Competitor[] { competitor1, competitor2, competitor3, competitor4, competitor5 };
            Competitor[] sortByDistance = new Competitor[] { competitor3, competitor2, competitor1, competitor4, competitor5 };
            QuickSort(contender, 0, contender.Length - 1, "Distance");
            CollectionAssert.AreEqual(sortByDistance, contender);
        }
        //***************************************Average Top Test**********************************************
        [TestMethod]
        public void AverageTopTest()
        {
            /*int[] list = new int[] { 6, 8, 18, 3, 22, 19, 58, 10 };
            int[] sortlist = new int[] { 3, 6, 8, 10, 18, 19, 22, 58 };
           Assert.AreEqual(3, SplitList(list, 0, list.Length - 1));*/
            var competitor1 = new Competitor(new int[] { 9, 2, 6, 3, 8 }, 1, "Popescu", 2);
            var competitor2 = new Competitor(new int[] { 8, 6, 7, 1, 3 }, 2, "Ionescu", 2);
            var competitor3 = new Competitor(new int[] { 9, 6, 5, 2, 2 }, 3, "Daniel", 2);
            var competitor4 = new Competitor(new int[] { 10, 5, 1, 3, 10 }, 4, "Grigore", 2);
            var competitor5 = new Competitor(new int[] { 4, 8, 9, 8, 11 }, 5, "Adrian", 2);

            Competitor[] contender = new Competitor[] { competitor1, competitor2, competitor3, competitor4, competitor5 };


        }

        //**********************************************Declaration******************************************

        //**************************************Competitor struct***********************************************
        public struct Competitor
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
        Competitor[] AverageSpeedTop(Competitor[] competitor)
        {
            QuickSort(competitor, 0, competitor.Length - 1, "Max Speed");
            return competitor;
        }
        //*********************************************Distance top***************************************************

        bool CaseCriteria(Competitor listElement,Competitor pivotElement,string criteria)
        {
            if (listElement.distance <= pivotElement.distance && criteria == "Distance") return true;
            if (listElement.maxSpeed <= pivotElement.maxSpeed && criteria == "Max Speed") return true;
            if (listElement.startNumber <= pivotElement.startNumber && criteria == "Start Position") return true;
            return false;
        }
        int SplitList(Competitor[] list,int first,int last,string criteria)
        {
            Competitor pivot = list[last];
            int pivotPosition = first;
            Competitor temp;
            int i;
           
            for ( i = first; i < last; i++)
            {
                if (CaseCriteria(list[i],pivot,criteria))
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
        public void QuickSort(Competitor[] list, int first,int last, string criteria)
        {  
            int positionPivot = SplitList(list, first, last,criteria);
            if (positionPivot > first)  QuickSort(list, first, positionPivot - 1, criteria); 
            if (positionPivot < last)  QuickSort(list, positionPivot + 1 ,last, criteria);        
        }

    }
}
