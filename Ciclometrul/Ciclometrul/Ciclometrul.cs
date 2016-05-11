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
 
           
           Assert.AreEqual(292, TotalDistance(contender));
        }
        //**********************************************MAx speed Test******************************************
        [TestMethod]
        public void MaxSpeedTest()
        {
            var competitor1 = new Competitor(new int[] { 9, 2, 6, 3, 8 }, 1, "Popescu",2);
            var competitor2 = new Competitor(new int[] { 8, 6, 7, 1, 3 }, 2, "Ionescu",2);
            var competitor3 = new Competitor(new int[] { 9, 6, 5, 2, 2 }, 3, "Daniel",2);
            var competitor4 = new Competitor(new int[] { 10, 5, 1, 3, 10 }, 4, "Grigore",2);
            var competitor5 = new Competitor(new int[] { 4, 8, 9, 8, 11 }, 5, "Adrian",2);

            Competitor[] contender = new Competitor[] { competitor1, competitor2, competitor3, competitor4, competitor5 };

            
            Assert.AreEqual("La secunda: 5 concurentul Adrian avea a atins viteza maxima de 22 m/s", MaxSpeedName(contender));
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
        //***************************************Average Speed Test**********************************************
        [TestMethod]
        public void AverageSpeedTopTest()
        {

            var competitor1 = new Competitor(new int[] { 9, 2, 6, 3, 8 }, 1, "Popescu", 2);
            var competitor2 = new Competitor(new int[] { 8, 6, 7, 1, 3 }, 2, "Ionescu", 2);
            var competitor3 = new Competitor(new int[] { 9, 6, 5, 2, 2 }, 3, "Daniel", 2);
            var competitor4 = new Competitor(new int[] { 10, 5, 1, 3, 10 }, 4, "Grigore", 2);
            var competitor5 = new Competitor(new int[] { 4, 8, 9, 8, 11 }, 5, "Adrian", 2);

            Competitor[] contender = new Competitor[] { competitor1, competitor2, competitor3, competitor4, competitor5 };
          
           Assert.AreEqual("Concurentul Adrian a avut cea mai buna viteza medie adica 16 m/s", AverageSpeedTop(contender));
        }
        //************************************Finish Order***********************************************************
        [TestMethod]
        public void FinishOrderTest()
        {

            var competitor1 = new Competitor(new int[] { 9, 2, 6, 3, 8 }, 1, "Popescu", 2);
            var competitor2 = new Competitor(new int[] { 8, 6, 7, 1, 3 }, 2, "Ionescu", 2);
            var competitor3 = new Competitor(new int[] { 9, 6, 5, 2, 2 }, 3, "Daniel", 2);
            var competitor4 = new Competitor(new int[] { 10, 5, 1, 3, 10 }, 4, "Grigore", 2);
            var competitor5 = new Competitor(new int[] { 4, 8, 9, 8, 11 }, 5, "Adrian", 2);

            Competitor[] contender = new Competitor[] { competitor1, competitor2, competitor3, competitor4, competitor5 };

            Assert.AreEqual("Ordinea de sosire a concurentilor a fost: Adrian  Grigore  Popescu  Ionescu  Daniel  ", FinishOrder(contender));
        }


        //**********************************************Declaration******************************************

        //**************************************Competitor struct***********************************************
        public struct Competitor
        {
            public int[] rotations;
            public string name;
            public int startNumber;
            public int lengthWheel;
            
        
            public Competitor(int[] rotations, int startNumber, string name, int lengthWheel)
            {
                this.rotations = rotations;
                this.startNumber = startNumber;
                this.name = name;
                this.lengthWheel = lengthWheel;
               
              
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
                        result[0] = i+1;
                        result[1] = rotations[i];
                    }
                    
                }
                return result;
            }
            public int averageSpeed()
            {
                int average = 0;
                for(int i = 0; i < rotations.Length; i++)
                {
                    average += rotations[i];
                }
                return average / rotations.Length;
            }
               
        
         }

        //*******************************************Total Distance calculation*******************************************
        int TotalDistance(Competitor[] competitor){
            int result = 0;
            for (int i = 0; i < competitor.Length; i++)
            {
                result += competitor[i].distance();
               
            }
            return result;
    }
        //*********************************************Max speed******************************************************
        string MaxSpeedName(Competitor[] competitor)
        {
            string MaxSpeed="";
            int maxSpeedCompare = 0;
            for (int i = 0; i < competitor.Length; i++)
            {   if (maxSpeedCompare < competitor[i].maxSpeed()[1])
                {
                    MaxSpeed = "La secunda: "+competitor[i].maxSpeed()[0].ToString()+" concurentul "+competitor[i].name+" avea a atins viteza maxima de "+(competitor[i].maxSpeed()[1]*competitor[i].lengthWheel).ToString()+" m/s";
                    
                }
                
                }            
            return MaxSpeed;
        }
        //*********************************************Average speed top**********************************************
        string AverageSpeedTop(Competitor[] competitor)
        {

            string averageSpeed = "";
            int averageSpeedCompare = 0;
            for (int i = 0; i < competitor.Length; i++)
            {
                if (averageSpeedCompare < competitor[i].averageSpeed())
                {
                    averageSpeed =  "Concurentul " + competitor[i].name + " a avut cea mai buna viteza medie adica " + (competitor[i].averageSpeed() * competitor[i].lengthWheel).ToString() + " m/s";

                }

            }
            return averageSpeed;
        }
        //*********************************************Distance top***************************************************
        string FinishOrder(Competitor[] competitor)
        {
            string order = "";
            QuickSort(competitor, 0, competitor.Length-1, "Distance");
            Array.Reverse(competitor);
            for(int i = 0; i < competitor.Length; i++)
            {
                order += competitor[i].name + "  ";
            }
            return "Ordinea de sosire a concurentilor a fost: " + order;
        }


        bool CaseCriteria(Competitor listElement, Competitor pivotElement, string criteria)
        {
            if (listElement.distance() <= pivotElement.distance() && criteria == "Distance") return true;
            if (listElement.maxSpeed()[1] <= pivotElement.maxSpeed()[1] && criteria == "Max Speed") return true;
            if (listElement.startNumber <= pivotElement.startNumber && criteria == "Start Position") return true;
            if (listElement.averageSpeed() <= pivotElement.averageSpeed() && criteria == "Average Speed") return true;
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
