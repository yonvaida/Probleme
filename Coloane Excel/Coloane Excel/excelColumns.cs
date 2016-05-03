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
        public void mColumnTest()
        {
            Assert.AreEqual("M", excelColumnName(13));
        }
        [TestMethod]
        public void aaColumnTest()
        {
            Assert.AreEqual("AA", excelColumnName(27));
        }
        [TestMethod]
        public void azColumnTest()
        {
            Assert.AreEqual("AZ", excelColumnName(52));
        }
        [TestMethod]
        public void bbColumnTest()
        {
            Assert.AreEqual("BB", excelColumnName(54));
        }
        [TestMethod]
        public void zzColumnTest()
        {
            Assert.AreEqual("ZZ", excelColumnName(702));
        }
        [TestMethod]
        public void aaccolumnTest()
        {
            Assert.AreEqual("AAC", excelColumnName(705));
        }
    string excelColumnName(int number)
        {
            string[] columnChar = { "Z","A", "B", "C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y"};
            string columnName;
            columnName = "";
            int rest;
            do
            {
                rest = number % 26;
                columnName = columnChar[rest]+columnName;
                if (rest == 0) { number = number - 1; };
                number = number / 26;
            } while (number > 0);
            return columnName;
        }
    }
}
