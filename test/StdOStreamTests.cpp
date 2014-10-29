//!
//! @file 			StdOStreamTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-10-29
//! @last-modified 	2014-10-29
//! @brief 			Tests the StdOStream class.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <cstdint>	// uint32_t, e.t.c

//====== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "../api/MIOStreamApi.hpp"
#include "../port/StdOStream/StdOStream.hpp"

using namespace MbeddedNinja;

namespace MIOStreamTestsNs
{
	MTEST_GROUP(StdOStreamTests)
	{

		MTEST(StdOStreamTest)
		{
			// Lets create a StdOStream and pass it std::cout
			StdOStream myStdOStream(&std::cout);

			myStdOStream << "This should display on std::cout!\r\n";

			//CHECK_EQUAL(myIOStringStream.myString, "000012");
		}

	}

} // namespace MIOStreamTestsNs
