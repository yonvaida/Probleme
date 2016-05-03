using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Loto
{
    [TestClass]
    public class loto
    {
        [TestMethod]
        public void ChanceCatI()
        {
            Assert.AreEqual(0.00000007, LotoProbability(6));
        }
        [TestMethod]
        public void ChanceCatII()
        {
            Assert.AreEqual(0.00001845, LotoProbability(5));
        }
        [TestMethod]
        public void ChanceCatIII()
        {
            Assert.AreEqual(0.00096862, LotoProbability(4));
        }
    }
}
