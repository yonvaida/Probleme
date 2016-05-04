using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Operatii_biti
{
    [TestClass]
    public class ByteOperations
    {
        //******************Convert to byte TEST******************************
        [TestMethod]
        public void NumberToBase2Test()
        {
            byte[] result = { 1, 1, 0, 0 };
            CollectionAssert.AreEqual(result, ConvertTo2(12));
        }
        //*********************NOT operation TEST**********************************
        [TestMethod]
        public void NOTOperationTest()
        {
            byte[] result = { 0, 0, 1, 1 };
            CollectionAssert.AreEqual(result, NOTOperation(ConvertTo2(12)));
        }
        //***********************AND operation TEST*********************************
        [TestMethod]
        public void ANDOperationTest()
        {
            byte[] result = { 1, 0, 0, 0 };
            CollectionAssert.AreEqual(result, ANDOperation(ConvertTo2(12), ConvertTo2(10)));
        }

        //******************Convert to byte******************************
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
            Array.Reverse(result);
            return result;
        }

        //*********************NOT operation**********************************
        byte[] NOTOperation(byte[] result)
        {
            for(int i=0; i < result.Length; i++)
            {
                if (result[i] == 0) result[i] = 1;
                else result[i] = 0;
            }
            return result;
        }

        //***********************AND operation*********************************
        byte[] ANDOperation(byte[] result,byte[] addedlist)
        {
            if (result.Length > addedlist.Length) Array.Resize(ref addedlist, result.Length);
            else Array.Resize(ref result, addedlist.Length);
            for (int i = 0; i < result.Length; i++)
            {
                if (result[i] == 1 && addedlist[i] == 1) result[i] = 1;
                else result[i] = 0;
            }
                return result;

        }

   }
}
