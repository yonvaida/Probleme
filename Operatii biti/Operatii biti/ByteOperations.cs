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
        [TestMethod]
        public void ANDOperationTest1()
        {
            byte[] result = { 0, 0, 0, 0 };
            CollectionAssert.AreEqual(result, ANDOperation(ConvertTo2(1), ConvertTo2(12)));
        }
        [TestMethod]
        public void ANDOperationTest2()
        {
            byte[] result = { 0, 1, 0, 0 };
            CollectionAssert.AreEqual(result, ANDOperation(ConvertTo2(12), ConvertTo2(4)));
        }


        //***********************OR operation TEST*********************************
        [TestMethod]
        public void OROperationTest()
        {
            byte[] result = { 1, 1, 1, 0 };
            CollectionAssert.AreEqual(result, OROperation(ConvertTo2(12), ConvertTo2(10)));
        }
        //***********************XOR operation TEST*********************************
        [TestMethod]
        public void XOROperationTest()
        {
            byte[] result = { 0, 1, 1, 0 };
            CollectionAssert.AreEqual(result, XOROperation(ConvertTo2(12), ConvertTo2(10)));
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
            if (result.Length > addedlist.Length)
            {
                Array.Reverse(addedlist);
                Array.Resize(ref addedlist, result.Length);
                Array.Reverse(addedlist);
            }
            else
            {
                Array.Reverse(result);
                Array.Resize(ref result, addedlist.Length);
                Array.Reverse(result);
            }
            for (int i = 0; i < result.Length; i++)
            {
                if (result[i] == 1 && addedlist[i] == 1) result[i] = 1;
                else result[i] = 0;
            }
                return result;

        }
        //***********************OR operation*********************************
        byte[] OROperation(byte[] result, byte[] addedlist)
        {
            if (result.Length > addedlist.Length)
            {
                Array.Reverse(addedlist);
                Array.Resize(ref addedlist, result.Length);
                Array.Reverse(addedlist);
            }
            else
            {
                Array.Reverse(result);
                Array.Resize(ref result, addedlist.Length);
                Array.Reverse(result);
            }
            for (int i = 0; i < result.Length; i++)
            {
                if (result[i] == 0 && addedlist[i] == 0) result[i] = 0;
                else result[i] = 1;
            }
            return result;

        }
        //***********************XOR operation*********************************
        byte[] XOROperation(byte[] result, byte[] addedlist)
        {
            if (result.Length > addedlist.Length)
            {
                Array.Reverse(addedlist);
                Array.Resize(ref addedlist, result.Length);
                Array.Reverse(addedlist);
            }
            else
            {
                Array.Reverse(result);
                Array.Resize(ref result, addedlist.Length);
                Array.Reverse(result);
            }
            for (int i = 0; i < result.Length; i++)
            {
                if ((result[i] == 0 && addedlist[i] == 1) || (result[i]==1 && addedlist[i]==0)) result[i] = 1;
                else result[i] = 0;
            }
            return result;

        }

    }
}
