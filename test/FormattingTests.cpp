//!
//! @file 			FormattingTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-10-29
//! @last-modified 	2014-10-29
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
	MTEST_GROUP(FormattingTests)
	{

		MTEST(PrecisionTest1)
		{
			OStringStream myIOStringStream;
			myIOStringStream.SetPrecision(6);

			myIOStringStream << 12;

			CHECK_EQUAL(myIOStringStream.myString, "000012");
		}

		MTEST(PrecisionTest2)
		{
			OStringStream myIOStringStream;
			myIOStringStream.SetPrecision(7);

			myIOStringStream << 12345;

			CHECK_EQUAL(myIOStringStream.myString, "0012345");
		}

		MTEST(PrecisionTest3)
		{
			OStringStream myIOStringStream;

			// Set the precision to 0, this should still print out the number correctly.
			myIOStringStream.SetPrecision(0);

			myIOStringStream << 12345;

			CHECK_EQUAL(myIOStringStream.myString, "12345");
		}

	}

} // namespace MIOStreamTestsNs
