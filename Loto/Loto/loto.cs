using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Loto
{
    [TestClass]
    public class loto
    {
        [TestMethod]
        public void MergesN7K3()
        {
            Assert.AreEqual(35, Merges(7,3));
        }
        [TestMethod]
        public void MergesN7K0()
        {
            Assert.AreEqual(1, Merges(7, 0));
        }
        [TestMethod]
        public void MergesN49K6()
        {
            Assert.AreEqual(13983816, Merges(49, 6));
        }
        [TestMethod]
        public void ChanceCatI()
        {
            Assert.AreEqual(1/13983816, LotoProbability(6));
        }
        [TestMethod]
        public void ChanceCatII()
        {
            Assert.AreEqual(1/54201, LotoProbability(5));
        }
        [TestMethod]
        public void ChanceCatIII()
        {
            Assert.AreEqual(1/1032, LotoProbability(4));
        }
        int Merges(int n,int k)
        {
            if (k == 0||n==k)
            {
                return 1;
            }else
            {
                return (Merges(n - 1, k - 1) + Merges(n - 1, k));
            }
        }
        decimal LotoProbability(int numbers)
        {
            return Merges(6, numbers) * Merges(43, 6 - numbers) / Merges(49, 6);
        }

    }
}
