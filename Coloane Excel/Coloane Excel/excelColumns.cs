using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Coloane_Excel
{
    [TestClass]
    public class excelColumns
    {
        [TestMethod]
        public void FirstColumnTest()
        {
            Assert.AreEqual("A", ExcelColumnName(1));
        }
        [TestMethod]
        public void MColumnTest()
        {
            Assert.AreEqual("M", ExcelColumnName(13));
        }
        [TestMethod]
        public void AAColumnTest()
        {
            Assert.AreEqual("AA", ExcelColumnName(27));
        }
        [TestMethod]
        public void AZColumnTest()
        {
            Assert.AreEqual("AZ", ExcelColumnName(52));
        }
        [TestMethod]
        public void BBColumnTest()
        {
            Assert.AreEqual("BB", ExcelColumnName(54));
        }
        [TestMethod]
        public void ZZColumnTest()
        {
            Assert.AreEqual("ZZ", ExcelColumnName(702));
        }
        [TestMethod]
        public void AAccolumnTest()
        {
            Assert.AreEqual("AAC", ExcelColumnName(705));
        }
    string ExcelColumnName(int number)
        {
            string columnName = "";
            do
            {
                int rest, columnChar;
                rest = number % 26;
                if (rest == 0) {
                    number = number - 1;
                    rest = 26;
                };
                columnChar = '@' + rest;
                columnName = (char)columnChar + columnName;
                number = number / 26;
            } while (number > 0);
            return columnName;
        }
    }
}
