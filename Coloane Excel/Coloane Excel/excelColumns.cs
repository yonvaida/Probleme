using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Coloane_Excel
{
    [TestClass]
    public class excelColumns
    {
        [TestMethod]
        public void TestMethod1()
        {
            Assert.AreEqual("A", excelColumnName(1));
        }
    }
}
