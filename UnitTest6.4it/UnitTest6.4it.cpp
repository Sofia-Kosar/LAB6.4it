#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB6.4it/LAB6.4it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
	TEST_CLASS(UnitTest64it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { -2, 109, -88, 4, 5, 34 };
			int n = 6;

			double z = Min(a, n);
			Assert::AreEqual(z, -2.0);
		}
	};
}
