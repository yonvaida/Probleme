using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Operatii_biti
{
    [TestClass]
    public class ByteOperations
    {
        [TestMethod]
        public void NumberToBase2Test()
        {
            Assert.AreEqual({1,1,0,0},ConvertTo2(12))
        }
    }
}
