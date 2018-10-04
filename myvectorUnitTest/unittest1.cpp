/*unittest1.cpp*/

//
// myvector class test harness
//
// <<Ativ Aggarwal>>
// U. of Illinois, Chicago
// CS341, Spring 2018
// Project #03
//

#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\myvector\myvector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace myvectorUnitTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test01)
		{
			//Test size for 100000 elements?
			myvector<int>  V;
			for (int i = 0; i < 100000; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.size() == 100000);
		}

		TEST_METHOD(Test02)
		{
			myvector<int>  V;
			myvector<int> Copy;
			for (int i = 0; i < 100; i++) {
				V.push_back(i);
			}

			Copy = V;
			Assert::IsTrue(Copy.front() == 0);
			Assert::IsTrue(Copy.back() == 999);

		}

		TEST_METHOD(Test03)
		{
			//Test if When there is only 1 element, is front==back?
			myvector<int>  V;

			V.push_back(1);
			Assert::IsTrue(V.size() == 1);
			Assert::IsTrue(V.front() == V.back());
		}


		TEST_METHOD(Test04)
		{
			//Test Capacity for 1000 elements?
			myvector<int>  V;
			for (int i = 0; i < 1000; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.capacity() == 1020);
		}

		TEST_METHOD(Test05)
		{
			//Test itrators?
			myvector<int>  V;
			for (int i = 0; i < 10000; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.begin()->front == 0);
			Assert::IsTrue(V.end()->back == 9999);
		}

		void helper_function1(myvector<int> V) {
			for (int i = 10000; i > 0; i--) {
				V.push_back(i);
			}
		}

		TEST_METHOD(Test06)
		{
			//Test copy constructor?
			myvector<int>  V;
			for (int i = 0; i < 10000; i++) {
				V.push_back(i);
			}

			helper_function1(V);
			for (int i = 0; i < 10000; i++)
			{
				Assert::IsTrue(V.operator[](i) == i);
			}
		}

		void helper_function2(myvector<int> &V) {
			for (int i = 10000; i > 0; i--) {
				V.push_back(i);
			}
		}


		TEST_METHOD(Test07)
		{
			//Test copy constructor?
			myvector<int>  V;
			for (int i = 0; i < 10000; i++) {
				V.push_back(i);
			}
			helper_function2(V);
			for (int i = 10000; i > 0; i--)
			{
				Assert::IsTrue(V.operator[](i) == i);
			}

		}
		
		TEST_METHOD(Test08)
		{
			//Test, nodes for 125 elements?
			myvector<int>  V;
			for (int i = 0; i < 125; i++) {
				V.push_back(i);
			}
			Assert::IsTrue(V.nodes() == 6);
		}

		TEST_METHOD(Test09)
		{
			//Test if When there is only 1 element, is front==back?
			myvector<int>  V;

			//V.push_back(1);
			Assert::IsFalse(V.operator[](1) == 1);
		}

		TEST_METHOD(Test10)
		{
			//Test if When there is only 1 element, is front==back?
			myvector<int>  V;

			Assert::IsFalse(V.size() == 1);
		}
	};
}