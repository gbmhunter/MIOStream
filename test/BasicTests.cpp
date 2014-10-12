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

		TestClass(MIOStream * myMIOStream)
		{
			this->myMIOStream = myMIOStream;
		}

		void Run()
		{
			*this->myMIOStream << "Testing";
		}

		MIOStream * myMIOStream;

	};

	MTEST(BasicTest)
	{
		MIOStringStream myMIOStringStream;

		TestClass myTestClass(&myMIOStringStream);

		myTestClass.Run();

		// Check capacity is calculated correctly
		CHECK_EQUAL(myMIOStringStream.myString, "Testing");
	}


} // namespace MIOStreamTestsNs
