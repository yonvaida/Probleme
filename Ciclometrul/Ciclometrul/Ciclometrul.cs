using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Ciclometrul
{
    [TestClass]
    public class Ciclometrul
    {
        [TestMethod]
        public void DistanceTest()
        {
            CompetitorStruct[] contender = new CompetitorStruct[2] {
                new CompetitorStruct { rotations = 10, lengthRoata = 2, name = "Popescu", startNumber = 1, totalTime = 300 },
                new CompetitorStruct { rotations = 8, lengthRoata = 2, name = "Ionescu", startNumber = 2, totalTime = 280 }
            };

            int[] result = { 6000, 4480 };
           CollectionAssert.AreEqual(result, Distance(contender));
        }

        struct CompetitorStruct{
        public int rotations;
        public int startNumber;
        public string name;
        public int totalTime;
        public int lengthRoata;
        
         }

        int[] Distance(CompetitorStruct[] Competitor)
    {
            var result = new int[2];
            for (int i = 0; i < 2; i++)
            {
                result[i] = Competitor[i].lengthRoata * Competitor[i].rotations * Competitor[i].totalTime;
            }
            return result;
    }

    }
}
