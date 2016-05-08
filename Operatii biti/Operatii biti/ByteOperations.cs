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
            byte[] result = { 0, 0, 1, 1 };
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
            var result = ConvertTo2(3);
            var testresult = NOTOperation(ConvertTo2(12));
           
            CollectionAssert.AreEqual(result,testresult );
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
        //**********************Reduce Array Size******************************************
        [TestMethod]
        public void ReduceArraySizeTest()
        {
            CollectionAssert.AreEqual(ConvertTo2(0), ReduceArraySize(new byte[] { 0, 0, 0, 0, 0, 0 }));
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
            var result = ConvertTo2(1 & 12);
            var tempResult = ANDOperation(ConvertTo2(1), ConvertTo2(12));

            CollectionAssert.AreEqual(result,tempResult );
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
            var tempResult = OROperation(ConvertTo2(12), ConvertTo2(10));
            Array.Reverse(tempResult);
            CollectionAssert.AreEqual(result, tempResult);
        }
        //***********************XOR operation TEST*********************************
        [TestMethod]
        public void XOROperationTest()
        {
            byte[] result = { 1, 1, 0 };
            var tempResult = XOROperation(ConvertTo2(12), ConvertTo2(10));
            Array.Reverse(tempResult);
            CollectionAssert.AreEqual(result, tempResult);
        }
        //***********************LeftShift operation TEST*********************************
        [TestMethod]
        public void LeftShiftOperationTest()
        {
            byte[] result = {0, 0, 0, 1, 1 };
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

            CollectionAssert.AreEqual(ConvertTo2(14), ADDOperation(ConvertTo2(12), ConvertTo2(2)));
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
            CollectionAssert.AreEqual(ConvertTo2(0), MultiplicationOperation(ConvertTo2(0), ConvertTo2(30)));
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
            Assert.AreEqual(false, EqualOperation(ConvertTo2(2), ConvertTo2(20)));
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
                return number[position];
            }

        }
        //*******************ReduceArraySize************************
        byte[] ReduceArraySize(byte[] number)
        {
            int i;
            for(i = number.Length-1; i >=0; i--)
            {
                if (number[i]==1) break;
                Array.Resize(ref number, i);
            }
            if (number.Length == 0) number = new byte[] { 0 };
            return number;        
        }
        //*********************NOT operation**********************************
        byte[] NOTOperation(byte[] result)
        {
            for (int i = 0; i < result.Length; i++)
            {
                result[i] = (byte)(result[i] == 0 ? 1 :0);
            }
            
            return ReduceArraySize(result); 
        }
        //***********************AND operation*********************************
        byte[] ANDOperation(byte[] first, byte[] second)
        {
                        
            return ExecuteOperations(first,second,"and");

        }
        byte[] ExecuteOperations(byte[] first,byte[] second, string operation)
        {
            var andResult = new byte[Math.Max(first.Length, second.Length)];

            for (int i = 0; i < andResult.Length; i++)
            {
                andResult[i] = (byte)(ConditionsOperations(GetAt(first,i),GetAt(second,i),operation) ? 1 : 0);

            }
            return ReduceArraySize(andResult);

        }
        bool ConditionsOperations(byte first, byte second, string operation)
        {
            if (operation == "and") return first == 1 && second == 1;
            if (operation== "or") return !(first == 0 && second == 0);
            if (operation == "xor") return !(first == second);
            return false;
        }
        //***********************OR operation*********************************
        byte[] OROperation(byte[] first, byte[] second)
        {
            return ExecuteOperations(first, second, "or");

        }
        //***********************XOR operation*********************************
        byte[] XOROperation(byte[] first, byte[] second)
        {
            return ExecuteOperations(first, second, "xor");

        }
        //***********************LeftShift operation*********************************
        byte[] LeftShiftOperation(byte[] number, int iteration)
        {
            Array.Reverse(number);
            Array.Resize(ref number, number.Length + iteration);
            Array.Reverse(number);
            return ReduceArraySize(number);
        }
        //***********************RightShift operation*********************************
        byte[] RightShiftOperation(byte[] result, int iteration)
        {
            if (result.Length > iteration)
            {
                Array.Reverse(result);
                Array.Resize(ref result, result.Length-iteration);
                Array.Reverse(result);
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
                var a = GetAt(first, i);
                var b = GetAt(second, i);
                addResult[i] = (byte)((a + b + transp)%2);
                transp = (a + b + transp) / 2;
            }
           
            return ReduceArraySize(addResult);
        }
        //***********************Subtract operation*********************************
        byte[] SubtractOperation(byte[] number1, byte[] number2)
        {
            var subResult = new byte[Math.Max(number1.Length, number2.Length)];
            if (LessThanOperation(number1, number2)==true){             
                return new byte[1]{ 0 };
            };
                
                Array.Resize(ref number2, number1.Length);
               
                
                subResult = (ADDOperation(number1, ADDOperation(NOTOperation(number2), new byte[] { 1 })));

           
                Array.Resize(ref subResult, number1.Length);
             
                return ReduceArraySize(subResult);

            }
        //***********************Multiplication operation*********************************
        byte[] MultiplicationOperation(byte[] number1,byte[] number2)
        {
            var result = new byte[] { 0};
            int t = 0;
            for(var i=new byte[] { 0}; LessThanOperation(i, number2);i= ADDOperation(i,new byte[]{ 1})){
                result = ADDOperation(result, number1);
            }
            return result;
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

                   divisionResult = ADDOperation(divisionResult, new byte[1] { 1 });
               };
               return divisionResult;
            
          
        }
        //***********************GratherThan operation*********************************
        bool GratherThanOperation(byte[] number1, byte[] number2)
        {
            return LessThanOperation(number2, number1);
           
        }
        //***********************Equal operation*********************************
        bool EqualOperation(byte[] number1, byte[] number2)
        {
            return !(LessThanOperation(number1, number2) || GratherThanOperation(number1, number2));
        }
        //***********************NotEqual operation*********************************
        bool NotEqualOperation(byte[] number1, byte[] number2)
        {
            if (EqualOperation(number1, number2)) return false;
            return true;
        }
    }
}