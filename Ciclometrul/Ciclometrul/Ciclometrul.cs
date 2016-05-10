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
        public void TotalDistanceTest()
        {
            var competitor1 = new Competitor(new int[] { 9,2,6,3,8 }, 1, "Popescu",2);
            var competitor2 = new Competitor(new int[] { 8,6,7,1,3 }, 2, "Ionescu",2);
            var competitor3 = new Competitor(new int[] { 9,6,5,2,2 }, 3, "Daniel",2);
            var competitor4 = new Competitor(new int[] { 10,5,1,3,10 }, 4, "Grigore",2);
            var competitor5 = new Competitor(new int[] {4,8,9,8,11 }, 5, "Adrian",2);

            Competitor[] contender = new Competitor[] {competitor1,competitor2,competitor3,competitor4,competitor5};
 
            int[] result = { 56, 50, 48, 58, 80 };
           CollectionAssert.AreEqual(result, TotalDistance(contender));
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
        public void AverageSpeedTopTest()
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
            int lengthWheel;
            
            int averageSpeed;
            public Competitor(int[] rotations, int startNumber, string name, int lengthWheel)
            {
                this.rotations = rotations;
                this.startNumber = startNumber;
                this.name = name;
                this.lengthWheel = lengthWheel;
                this.averageSpeed = 0;
              
            }
            public int distance()
            {
                int result = 0;
                for (int i = 0; i < rotations.Length; i++)
                {
                    result += rotations[i] * lengthWheel;
                }
                return result;
            }
            public int[] maxSpeed()
            {
                var result = new int[2] {0,0};
                for (int i = 0; i < rotations.Length; i++)
                {
                    if (rotations[i] > result[1])
                    {
                        result[0] = i;
                        result[1] = rotations[i];
                    }
                    
                }
                return result;
            }
            
               
        
         }
        //******************************************Competitor Distance**************************************************
    


        //*******************************************Total Distance calculation*******************************************
        int[] TotalDistance(Competitor[] competitor){
            var result = new int[competitor.Length];
            for (int i = 0; i < competitor.Length; i++)
            {
                result[i] = competitor[i].distance();
               
            }
            return result;
    }
        //*********************************************Max speed******************************************************
        string[] MaxSpeedName(Competitor[] competitor)
        {
            var MaxSpeed=new string[competitor.Length] ;
            for (int i = 0; i < competitor.Length; i++)
            {
                MaxSpeed[i] = competitor[i].maxSpeed()[1].ToString(); 
                }            
            return MaxSpeed;
        }

        //*********************************************Average speed top**********************************************
        Competitor[] AverageSpeedTop(Competitor[] competitor)
        {
            QuickSort(competitor, 0, competitor.Length - 1, "Max Speed");
            return competitor;
        }
        //*********************************************Distance top***************************************************

        bool CaseCriteria(Competitor listElement, Competitor pivotElement, string criteria)
        {
            if (listElement.distance() <= pivotElement.distance() && criteria == "Distance") return true;
            if (listElement.maxSpeed()[1] <= pivotElement.maxSpeed()[1] && criteria == "Max Speed") return true;
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
