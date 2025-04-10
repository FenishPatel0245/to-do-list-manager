#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


extern "C" {
#include "../todolist/todolist.h"
}
namespace todolistUnitTest
{
	TEST_CLASS(todolistUnitTest)
	{
	public:
		
		TEST_METHOD(ValidateDate_Valid)
		{
			Assert::IsTrue(validate_date("2025-04-09"));
			Assert::IsTrue(validate_date("2025/04/09"));
			Assert::IsTrue(validate_date("2000-01-01"));
			Assert::IsTrue(validate_date("2100-12-31"));
		}
	};
}
