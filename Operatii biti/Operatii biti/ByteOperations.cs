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
            byte[] result = { 0, 0, 1, 1 };
            CollectionAssert.AreEqual(result, ConvertTo2(12));
        }
        [TestMethod]
        public void NotOperationTest()
        {
            byte[] result = { 1, 1, 0, 0 };
            CollectionAssert.AreEqual(result, NotOperation(ConvertTo2(12)));
        }
        [TestMethod]
       


        byte[] ConvertTo2(int number)
        {
            byte[] result=new byte[1];
            int i=0;
            do
            {
                Array.Resize(ref result,i+1);
                int tempbyte;
                tempbyte = number % 2;
                result[i] = (byte)tempbyte;
                number = number / 2;
                i++;
            } while (number > 0);
            return result;
        }
        byte[] NotOperation(byte[] result)
        {
            int length = result.Length;
            for(int i=0; i < length; i++)
            {
                if (result[i] == 0) result[i] = 1;
                else result[i] = 0;
            }
            return result;
        }
    }
}
