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
            CompetitorStruct contender = new CompetitorStruct { rotations = 10, lungimeRoata = 2, startNumber=1,Time=30 }; 
            Assert.AreEqual(600, Distance(contender));
        }

        struct CompetitorStruct{
        public int rotations;
        public int startNumber;
        public int Time;
        public int lungimeRoata;
        
         }

        int Distance(CompetitorStruct Competitor)
    {
       return Competitor.lungimeRoata*Competitor.rotations*Competitor.Time;
    }

    }
}
