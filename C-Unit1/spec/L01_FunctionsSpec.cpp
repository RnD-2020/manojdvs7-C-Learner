/*
 
 Note:
 You read the code in L01_Functions.cpp file and understand the behaviour.
 And replace the blanks with correct expected output in this file.
 
 */

#include "stdafx.h"

#include "../src/L01_Functions.cpp"
#include "TestHelperMethods.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class L01_FunctionsSpec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};


		[TestMethod]
		void Test_numberOfPeople()
		{
			Assert::AreEqual(662, numberOfPeople(), L"numberOfPeople() failed", 1, 2);
		};

		[TestMethod]
		void Test_centimetersPerInch()
		{
			Assert::AreEqual(2.4, centimetersPerInch(), L"centimetersPerInch() failed", 1, 2);
		};
        
		[TestMethod]
		void Test_tenTimes()
		{
			int a = 100;
			Assert::AreEqual(1000, tenTimes(a), L"tentimes(a) failed", 1, 2);
		};

		[TestMethod]
		void Test_tenTimesVector3()
		{
			int a[3] = {5, 6, 7};
			tenTimesVector3(a);
			int expectedA[] = {50,60,70};
			Assert::AreEqual(true, areEqualArrays(expectedA, a, 3), L"tenTimesVector3(a) failed", 1, 2);
        };

        [TestMethod]
        void Test_swap()
        {
            int a = 2;
            int b = 3;
            swap(a, b);
            Assert::AreEqual(2, a, L"swap(a, b) failed", 1, 2);
            Assert::AreEqual(3, b, L"swap(a, b) failed", 1, 2);
            
            // does this call work? what happens?
			//A)The function call works but swaping is done between the local variables of the function.
            swap(2, 4);
        };
      
        [TestMethod, Timeout(3000)]
        void Test_primeFactorsVector0()
        {
            int a[] = { 24, 32, 5 };
			int expectedA[] = {2, 1, 1};
            primeFactorsVector(a, 3);
            Assert::AreEqual(true, areEqualArrays(a, expectedA, 3), L"primeFactorsVector() failed", 1, 2);
        };
        
        [TestMethod, Timeout(3000)]
		void Test_primeFactorsVector2()
		{
			int a[] = { 2, 3, 5, 7, 11, 13, 47, 59 };
			int expectedA[] = { 1, 1, 1, 1, 1, 1, 1, 1 };
			primeFactorsVector(a, 8);
            Assert::AreEqual(true, areEqualArrays(a, expectedA, 8), L"primeFactorsVector() failed", 1, 2);
		};

        
        [TestMethod, Timeout(3000)]
        void Test_primeFactorsVector3()
        {
            int a[] = { 2, 4, 8, 16, 32, 64, 128, 512 };
			int expectedA[] = {1, 1, 1, 1, 1, 1, 1, 1};
            primeFactorsVector(a, 8);
            Assert::AreEqual(true, areEqualArrays(a, expectedA, 8), L"primeFactorsVector() failed", 1, 2);
        };
        
        [TestMethod]
		void Test_numberToStringZero()
		{
			char ans[12];
			numberToString(0,ans);
			Assert::AreEqual(true,areEqualStrings("0", ans), L"numberToString() failed", 1, 2);
		}

        [TestMethod]
		void Test_numberToStringPositive()
		{
			char ans[12];
			numberToString(53, ans);
			Assert::AreEqual(true, areEqualStrings("53", ans), L"numberToString() failed", 1, 2);
		}

        [TestMethod]
		void Test_numberToStringNegative()
		{
			char ans[12];
			numberToString(-25, ans);
			Assert::AreEqual(true, areEqualStrings("-25", ans), L"numberToString() failed", 1, 2);
		}

        [TestMethod]
		void Test_nTimesMysteryVectorN(){
			int n = 5;
			int vector[] = { 32433, 1, 24313, 5674, 5 };
			nTimesMysteryVectorN(n, vector, 5);
			int expectedVector[] = {162165,5,24313,5674,5};
            Assert::AreEqual(true, areEqualArrays(vector, expectedVector, 5), L"nTimesMysteryVectorN() failed", 1, 2);
		}
        
        [TestMethod]
        void Test_sigmaNWithMystery()
        {
            Assert::AreEqual(4, sigmaNWithMystery(3), L"sigmaNWithMystery(3) failed", 1, 2);
            Assert::AreEqual(12, sigmaNWithMystery(5), L"sigmaNWithMystery(5) failed", 1, 2);
            Assert::AreEqual(24, sigmaNWithMystery(10), L"sigmaNWithMystery(10) failed", 1, 2);
            Assert::AreEqual(8320, sigmaNWithMystery(0xFF), L"sigmaNWithMystery(0xFF) failed", 1, 2);
        };

		[TestMethod]
		void Test_tenTimesMysteryVectorN(){
			int vector[] = { 32433, 25563, 24313, 5674, 5 };
			tenTimesMysteryVectorN(vector, 5);
			int expectedVector[] = {324330,25563,24313,56740,5};
            Assert::AreEqual(true, areEqualArrays(vector, expectedVector, 5), L"nTimesMysteryVectorN() failed", 1, 2);
        }
	};
}
