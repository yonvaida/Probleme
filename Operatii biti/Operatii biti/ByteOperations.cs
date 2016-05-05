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
        //******************Convert to decimal TEST******************************
        [TestMethod]
        public void ConvertTo10Test()
        {
            byte[] result = { 1, 1, 0, 0 };
            Assert.AreEqual(12, ConvertTo10(result));
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
            
            CollectionAssert.AreEqual(ConvertTo2(12 & 10), ANDOperation(ConvertTo2(12), ConvertTo2(10)));
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
        //***********************LeftShift operation TEST*********************************
        [TestMethod]
        public void LeftShiftOperationTest()
        {
            byte[] result = { 1, 0, 0, 0 };
            CollectionAssert.AreEqual(result, LeftShiftOperation(ConvertTo2(12), 1));
        }
        //***********************RightShift operation TEST*********************************
        [TestMethod]
        public void RightShiftOperationTest()
        {
            byte[] result = { 0, 0, 1, 1 };
            CollectionAssert.AreEqual(result, RightShiftOperation(ConvertTo2(12), 2));
        }
        //***********************Lessthan operation TEST*********************************
        [TestMethod]
        public void LessThanOperationTest()
        {

        }
        //***********************ADD operation TEST*********************************
        [TestMethod]
        public void ADDOperationTest()
        {

            Assert.AreEqual(142, ConvertTo10(ADDOperation(ConvertTo2(127), ConvertTo2(15))));
        }
        //***********************Subtract operation TEST*********************************
        [TestMethod]
        public void SubtractOperationTest()
        {
            byte[] result = { 1, 1, 1, 0, 1 };
            CollectionAssert.AreEqual(result, SubtractOperation(ConvertTo2(142), ConvertTo2(113)));
        }

        //******************Convert to byte******************************
        byte[] ConvertTo2(int number)
        {
            byte[] result = new byte[1];
            int i = 0;
            do
            {
                Array.Resize(ref result, i + 1);
                int tempbyte;
                tempbyte = number % 2;
                result[i] = (byte)tempbyte;
                number = number / 2;
                i++;
            } while (number > 0);
            Array.Reverse(result);
            return result;
        }
        //******************Convert to decimal******************************
        double ConvertTo10(byte[] result)
        {
            Array.Reverse(result);
            double number = 0;
            for (int i = 0; i < result.Length; i++)
            {
                number = number + Math.Pow(2, i) * (int)result[i];
            }
            return number;
        }


        //*********************NOT operation**********************************
        byte[] NOTOperation(byte[] result)
        {
            for (int i = 0; i < result.Length; i++)
            {
                result[i] = (result[i]==0) ? (byte)1 : (byte)0;
            }
            return result;
        }

        //***********************AND operation*********************************
        byte[] ANDOperation(byte[] result, byte[] addedlist)
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
                if ((result[i] == 0 && addedlist[i] == 1) || (result[i] == 1 && addedlist[i] == 0)) result[i] = 1;
                else result[i] = 0;
            }
            return result;

        }

        //***********************LeftShift operation*********************************
        byte[] LeftShiftOperation(byte[] result, int iteration)
        {
            byte[] resultTemp = result;
            Array.Resize(ref resultTemp, result.Length + iteration);
            for (int i = 0; i < result.Length; i++)
            {
                result[i] = resultTemp[i + iteration];
            } 
            return result;
        }
        //***********************RightShift operation*********************************
        byte[] RightShiftOperation(byte[] result, int iteration)
        {
            Array.Reverse(result);
            result = LeftShiftOperation(result, iteration);
            Array.Reverse(result);
            return result;
        }

        //***********************LessThan operation***********************************

        //***********************ADD operation****************************************
        byte[] ADDOperation(byte[] number1, byte[] number2)
        {

            Array.Reverse(number1);
            Array.Reverse(number2);
            if (number1.Length > number2.Length)
            {
                Array.Resize(ref number1, number1.Length + 1);
                Array.Resize(ref number2, number1.Length);
            }
            else
            {
                Array.Resize(ref number1, number2.Length + 1);
                Array.Resize(ref number2, number2.Length + 1);
            };
            byte transp = 0;
            for (int i = 0; i < number1.Length; i++)
            {
                int sumtemp = (int)number1[i] + (int)number2[i] + (int)transp;
                number1[i] = (byte)(sumtemp % 2);
                transp = (byte)(sumtemp / 2);
            }
            Array.Reverse(number1);
            return number1;
        }

        //***********************Subtract operation*********************************
        byte[] SubtractOperation(byte[] number1, byte[] number2)
        {
            double resulttemp = ConvertTo10(number1) - ConvertTo10(number2);
            int result = (int)resulttemp;
            return ConvertTo2(result);
        }

        //***********************Multiplication operation*********************************

        //***********************Division operation*********************************

        //***********************GratherThan operation*********************************

        //***********************Equal operation*********************************

        //***********************NotEqual operation*********************************
    }
}