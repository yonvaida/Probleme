using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Operatii_biti
{
    [TestClass]
    public class ByteOperations
    {

//-----------------------------------------------------TESTS--------------------------------------------------

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
        //******************GetAt positio TEST******************************
        [TestMethod]
        public void GetAtTest()
        {
            Assert.AreEqual(0, GetAt(ConvertTo2(12), 0));
        }
        [TestMethod]
        public void GetAtTest1()
        {
            Assert.AreEqual(0, GetAt(ConvertTo2(12), 1));
        }
        [TestMethod]
        public void GetAtTest2()
        {
            Assert.AreEqual(1, GetAt(ConvertTo2(12), 2));
        }
        [TestMethod]
        public void GetAtTest3()
        {
            Assert.AreEqual(1, GetAt(ConvertTo2(12), 3));
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

            CollectionAssert.AreEqual(ConvertTo2(1 & 12), ANDOperation(ConvertTo2(1), ConvertTo2(12)));
        }
        [TestMethod]
        public void ANDOperationTest2()
        {

            CollectionAssert.AreEqual(ConvertTo2(12 & 4), ANDOperation(ConvertTo2(12), ConvertTo2(4)));
        }
        //***********************OR operation TEST*********************************
        [TestMethod]
        public void OROperationTest()
        {
            byte[] result = {1, 1, 1, 0 };
            CollectionAssert.AreEqual(result, OROperation(ConvertTo2(12), ConvertTo2(10)));
        }
        //***********************XOR operation TEST*********************************
        [TestMethod]
        public void XOROperationTest()
        {
            byte[] result = { 1, 1, 0 };
            CollectionAssert.AreEqual(result, XOROperation(ConvertTo2(12), ConvertTo2(10)));
        }
        //***********************LeftShift operation TEST*********************************
        [TestMethod]
        public void LeftShiftOperationTest()
        {
            byte[] result = {1, 1, 0, 0, 0 };
            CollectionAssert.AreEqual(result, LeftShiftOperation(ConvertTo2(12), 1));
        }
        //***********************RightShift operation TEST*********************************
        [TestMethod]
        public void RightShiftOperationTest()
        {
            byte[] result = { 1, 1 };
            CollectionAssert.AreEqual(result, RightShiftOperation(ConvertTo2(12), 2));
        }
        //***********************Lessthan operation TEST*********************************
        [TestMethod]
        public void LessThanOperationTest()
        {
            Assert.AreEqual(true, LessThanOperation(ConvertTo2(10), ConvertTo2(11)));
        }
        //***********************ADD operation TEST*********************************
        [TestMethod]
        public void ADDOperationTest()
        {

            Assert.AreEqual(14, ConvertTo10(ADDOperation(ConvertTo2(12), ConvertTo2(2))));
        }
        //***********************Subtract operation TEST*********************************
        [TestMethod]
        public void SubtractOperationTest()
        {
            CollectionAssert.AreEqual(ConvertTo2(6), SubtractOperation(ConvertTo2(8), ConvertTo2(2)));
        }
        //***********************Multiplication operation TEST****************************
        [TestMethod]
        public void MultiplicationOperationTest()
        {
            CollectionAssert.AreEqual(ConvertTo2(21), MultiplicationOperation(ConvertTo2(3), ConvertTo2(7)));
        }
        //************************Division operation TEST***********************************
        [TestMethod]
        public void DivisionOperationTest()
        {
            CollectionAssert.AreEqual(ConvertTo2(2), DivisionOperation(ConvertTo2(20), ConvertTo2(7)));
        }
        //************************Equal operation TEST***********************************
        [TestMethod]
        public void EqualOperationTest()
        {
            Assert.AreEqual(true, EqualOperation(ConvertTo2(20), ConvertTo2(20)));
        }
        //************************GratherThan operation TEST***********************************
        [TestMethod]
        public void GratherThanOperationTest()
        {
            Assert.AreEqual(true, GratherThanOperation(ConvertTo2(20), ConvertTo2(5)));
        }
        //************************NotEqual operation TEST***********************************
        [TestMethod]
        public void NotEqualOperationTest()
        {
            Assert.AreEqual(true, NotEqualOperation(ConvertTo2(20), ConvertTo2(19)));
        }


        //-------------------------------------------------------Declaration---------------------------------------


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
        //**********************GetAT operation*********************
        byte GetAt(byte[] number, int position)
        {
            if (position >= number.Length)
            {
                return (byte)0;
            }
            else
            {
                return number[number.Length - position - 1];
            }

        }
        //*******************ReduceArraySize************************
        byte[] ReduceArraySize(byte[] number)
        {
            return ConvertTo2((int)ConvertTo10(number));
        }
        //*********************NOT operation**********************************
        byte[] NOTOperation(byte[] result)
        {
            for (int i = 0; i < result.Length; i++)
            {
                result[i] = (byte)(result[i] == 0 ? 1 :0);
            }
            return result;
        }
        //***********************AND operation*********************************
        byte[] ANDOperation(byte[] first, byte[] second)
        {
            var andResult = new byte[Math.Max(first.Length, second.Length)];
           
            for (int i = 0; i < andResult.Length; i++)
            {
                andResult[i] = (byte)(GetAt(first, i) == 1 && GetAt(second, i) == 1 ? 1 : 0);
                
            }
            Array.Reverse(andResult);
            return ReduceArraySize(andResult);

        }
        //***********************OR operation*********************************
        byte[] OROperation(byte[] first, byte[] second)
        {
            var orResult = new byte[Math.Max(first.Length, second.Length)];
            for (int i = 0; i < orResult.Length; i++)
            {
                orResult[i] = (byte)(GetAt(first, i) == 0 && GetAt(second, i) == 0 ? 0 : 1);
            }
            Array.Reverse(orResult);
            return ReduceArraySize(orResult);

        }
        //***********************XOR operation*********************************
        byte[] XOROperation(byte[] first, byte[] second)
        {
            var xorResult = new byte[Math.Max(first.Length, second.Length)];
            for (int i = 0; i < xorResult.Length; i++)
            {
                xorResult[i] = (byte)((GetAt(first, i) == 0 && GetAt(second, i)==1)||(GetAt(first, i) == 1 && GetAt(second, i)==0)  ? 1 : 0);
            }
            Array.Reverse(xorResult);
            return ReduceArraySize(xorResult);

        }
        //***********************LeftShift operation*********************************
        byte[] LeftShiftOperation(byte[] number, int iteration)
        {
            Array.Resize(ref number, number.Length + iteration);
            return number;
        }
        //***********************RightShift operation*********************************
        byte[] RightShiftOperation(byte[] result, int iteration)
        {
            if (result.Length > iteration)
            {
                Array.Resize(ref result, result.Length-iteration);
                return ReduceArraySize(result);
            }
            else
            {
                return new byte[1] { 0 };
            }            
        }
        //***********************LessThan operation***********************************
        bool LessThanOperation(byte[] first,byte[] second)
        {
            bool result=false;
            for(int i =0;i< Math.Max(first.Length, second.Length); i++) {
                if (GetAt(first, Math.Max(first.Length, second.Length)-i-1) < GetAt(second, Math.Max(first.Length, second.Length)-i-1))
                {
                    result= true;
                    break;
                };
                if (GetAt(first, Math.Max(first.Length, second.Length) - i - 1) > GetAt(second, Math.Max(first.Length, second.Length) - i - 1))
                {
                    result = false;
                    break;
                };
            };
            return result;
        }
        //***********************ADD operation****************************************
        byte[] ADDOperation(byte[] first, byte[] second)
        {
            var addResult = new byte[Math.Max(first.Length, second.Length) + 1];
            int transp = 0;
            for(int i = 0; i < addResult.Length; i++)
            { 
                addResult[i] = (byte)((GetAt(first, i) + GetAt(second, i) + transp)%2);
                transp = (GetAt(first, i) + GetAt(second, i) + transp) / 2;
            }
            Array.Reverse(addResult);
            return ReduceArraySize(addResult);
        }
        //***********************Subtract operation*********************************
        byte[] SubtractOperation(byte[] number1, byte[] number2)
        {
            var subResult = new byte[Math.Max(number1.Length, number2.Length)];
            if (LessThanOperation(number1, number2)==true){             
                return new byte[1]{ 0 };
            };
                Array.Reverse(number2);
                Array.Resize(ref number2, number1.Length);
                Array.Reverse(number2);
                
                subResult = (ADDOperation(number1, ADDOperation(NOTOperation(number2), new byte[] { 1 })));

                Array.Reverse(subResult);
                Array.Resize(ref subResult, number1.Length);
                Array.Reverse(subResult);        
                return ReduceArraySize(subResult);

            }
        //***********************Multiplication operation*********************************
        byte[] MultiplicationOperation(byte[] number1,byte[] number2)
        {
            var result = new byte[number1.Length];
            for(int i = 0; i < number2.Length; i++)
            {
                if (GetAt(number2, i) == 1)
                {
                    Array.Reverse(result);
                    Array.Resize(ref result, number1.Length + i);
                    Array.Reverse(result);
                    result = ADDOperation(result, LeftShiftOperation(number1, i));
                }    
            }
            return ReduceArraySize(result);
        }
        //***********************Division operation*********************************
        byte[] DivisionOperation(byte[] number1,byte[] number2)
        {
            if (LessThanOperation(number1, number2))
            {
                return new byte[1] { 0 };
            }
            var divisionResult = new byte[number1.Length];
            byte[] tempNumber = number1;
            while (LessThanOperation(number2, tempNumber) || EqualOperation(number2,tempNumber)) 
            {
                tempNumber = SubtractOperation(tempNumber, number2);
                Array.Reverse(number2);
                divisionResult = ADDOperation(divisionResult, new byte[1] { 1 });
            };
            return divisionResult;
        }
        //***********************GratherThan operation*********************************
        bool GratherThanOperation(byte[] number1, byte[] number2)
        {
            if (LessThanOperation(number1, number2) || EqualOperation(number1, number2)) return false;       
            return true;
        }
        //***********************Equal operation*********************************
        bool EqualOperation(byte[] number1, byte[] number2)
        {
            ReduceArraySize(number1);
            ReduceArraySize(number2);
            if(number1.Length != number2.Length) return false;
            for(int i = 0; i < number1.Length; i++)
            {
                if (GetAt(number1, i) != GetAt(number2, i)) return false;
            }
            return true;
        }
        //***********************NotEqual operation*********************************
        bool NotEqualOperation(byte[] number1, byte[] number2)
        {
            if (EqualOperation(number1, number2)) return false;
            return true;
        }

    }
}