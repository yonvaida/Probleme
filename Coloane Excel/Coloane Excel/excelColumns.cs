using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Coloane_Excel
{
    [TestClass]
    public class excelColumns
    {
        [TestMethod]
        public void firstColumnTest()
        {
            Assert.AreEqual("A", excelColumnName(1));
        }
        [TestMethod]
        public void aaColumnTest()
        {
            Assert.AreEqual("AA", excelColumnName(1));
        }
    string excelColumnName(int number)
        {
            string[] columnName = { "","A", "B", "C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
            
        }
    }
}
