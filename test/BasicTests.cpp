//!
//! @file 			BasicTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-10-12
//! @last-modified 	2014-10-13
//! @brief 			Contains basic tests.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <cstdint>	// uint32_t, e.t.c

//====== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "../api/MIOStreamApi.hpp"

using namespace MbeddedNinja;

namespace MIOStreamTestsNs
{

	class TestClass
	{
		public:

		TestClass(IOStream * myMIOStream)
		{
			this->myMIOStream = myMIOStream;
		}

		void Run()
		{
			*this->myMIOStream << "Testing";
		}

		IOStream * myMIOStream;

	};

	MTEST(BasicTest)
	{
		IOStringStream myMIOStringStream;

		TestClass myTestClass(&myMIOStringStream);

		myTestClass.Run();

		CHECK_EQUAL(myMIOStringStream.myString, "Testing");
	}

	MTEST(Uint8Test)
	{
		IOStringStream myMIOStringStream;

		myMIOStringStream << (uint8_t)45;

		CHECK_EQUAL(myMIOStringStream.myString, "45");
	}

	MTEST(Int8Test)
	{
		IOStringStream myMIOStringStream;

		myMIOStringStream << (int8_t)-12;

		CHECK_EQUAL(myMIOStringStream.myString, "-12");
	}

	MTEST(Uint16Test)
	{
		IOStringStream myMIOStringStream;

		myMIOStringStream << (uint16_t)765;

		CHECK_EQUAL(myMIOStringStream.myString, "765");
	}

	MTEST(Int16Test)
	{
		IOStringStream myMIOStringStream;

		myMIOStringStream << (int16_t)-1765;

		CHECK_EQUAL(myMIOStringStream.myString, "-1765");
	}

	MTEST(Uint32Test)
	{
		IOStringStream myMIOStringStream;

		myMIOStringStream << (uint32_t)1234567;

		CHECK_EQUAL(myMIOStringStream.myString, "1234567");
	}

	MTEST(Int32Test)
	{
		IOStringStream myMIOStringStream;

		myMIOStringStream << (int32_t)-1234567;

		CHECK_EQUAL(myMIOStringStream.myString, "-1234567");
	}

	MTEST(Uint64Test)
	{
		IOStringStream myMIOStringStream;

		myMIOStringStream << (uint64_t)123456789123456789;

		CHECK_EQUAL(myMIOStringStream.myString, "123456789123456789");
	}

	MTEST(Int64Test)
	{
		IOStringStream myMIOStringStream;

		myMIOStringStream << (int64_t)-123456789123456789;

		CHECK_EQUAL(myMIOStringStream.myString, "-123456789123456789");
	}


} // namespace MIOStreamTestsNs
