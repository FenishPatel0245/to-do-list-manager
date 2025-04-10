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

		TEST_METHOD(ValidateDate_InvalidFormat)
		{
			Assert::IsFalse(validate_date("2025-4-9"));
			Assert::IsFalse(validate_date("2025-04/09"));
			Assert::IsFalse(validate_date("2025.04.09"));
			Assert::IsFalse(validate_date("2025*04*09"));
			Assert::IsFalse(validate_date("20a5-04-09"));
			Assert::IsFalse(validate_date("2025-13-09"));
			Assert::IsFalse(validate_date("2025-04-32"));
			Assert::IsFalse(validate_date("1999-12-31"));
			Assert::IsFalse(validate_date("2101-01-01"));
			Assert::IsFalse(validate_date(""));
		}
		TEST_METHOD(ValidateTime_Valid)
		{
			Assert::IsTrue(validate_time("09:45"));
			Assert::IsTrue(validate_time("23:00"));
			Assert::IsTrue(validate_time("00:00"));
			Assert::IsTrue(validate_time("23:59"));
		}

		TEST_METHOD(ValidateTime_Invalid)
		{
			Assert::IsFalse(validate_time("9:45"));
			Assert::IsFalse(validate_time("0945"));
			Assert::IsFalse(validate_time("09-45"));
			Assert::IsFalse(validate_time("24:00"));
			Assert::IsFalse(validate_time("12:60"));
			Assert::IsFalse(validate_time("3:5"));
			Assert::IsFalse(validate_time("12:5"));
			Assert::IsFalse(validate_time("1:45"));
			Assert::IsFalse(validate_time(""));
		}


	};
}
