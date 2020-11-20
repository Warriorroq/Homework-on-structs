#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		Vector3 vec;
		Vector3 vec2;

		TEST_METHOD_INITIALIZE(init) {
			vec = Vector3(1, 1, 1);
			vec2 = Vector3(1, 1, 1);
		}

		TEST_METHOD(test0)
		{
			vec += Vector3(1, 2, 1);
			vec2 *= 2;
			vec2 -= Vector3(0, -1, 0);
			Assert::IsTrue(vec == vec2);
		}
		TEST_METHOD(test1)
		{

			vec += Vector3(3,3,3);
			vec2 *= 4;
			vec /= 2;
			vec2 /= 2;

			Assert::IsTrue(vec == vec2);
		}
	};
}
