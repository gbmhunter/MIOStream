//!
//! @file				MIOStream.cpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-10-12
//! @last-modified		2014-10-12
//! @brief				Contains the definitions for the MString class.
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <cstdint>		// int8_t, int32_t e.t.c
#include <cstring>		// strlen(), strncpy()
#include <cstdio>		// snprintf()
#include <cinttypes>	// PRId8, PRId32, e.t.c
//#include <iostream>		//!< @debug

//===== USER LIBRARIES =====//
// none

//===== USER SOURCE =====//
#include "../include/MIOStream.hpp"




namespace MbeddedNinja
{

	//! @brief		The maximum number of characters used when shifting a double onto a string.
	//! @details	Determines the size of the temporary buffer created on the stack when adding
	//!				a double to a string via the '<<' operator.
	constexpr uint16_t maxNumCharsForDouble = 20;


	MIOStream & MIOStream::operator << (uint8_t myUint8)
	{
		// New to convert unsigned int into a string
		// We will need a maximum of 3 chars to represent a 8-bit unsigned int
		// (range is 0 to 255 inclusive)
		char tempBuff[4];
		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%" PRIu8,
			myUint8);
		// Add converted number to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	MIOStream & MIOStream::operator << (int8_t myInt8)
	{
		// New to convert unsigned int into a string
		// We will need a maximum of 4 chars to represent a 8-bit signed number
		// (range is -127 to 127 inclusive)
		char tempBuff[5];
		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%" PRIi8,
			myInt8);
		// Add converted number to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	MIOStream & MIOStream::operator << (uint16_t myUint16)
	{
		// New to convert unsigned int into a string
		// We will need a maximum of 5 chars to represent a 16-bit unsigned number
		// (range is 0 to 65535 inclusive)
		char tempBuff[6];
		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%" PRIu16,
			myUint16);
		// Add converted number to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	MIOStream & MIOStream::operator << (int16_t myInt16)
	{
		// New to convert unsigned int into a string
		// We will need a maximum of 6 chars to represent a 16-bit signed number
		// (range is -32767 to 32767 inclusive)
		char tempBuff[7];
		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%" PRIi16,
			myInt16);
		// Add converted number to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	MIOStream & MIOStream::operator << (uint32_t myUint32)
	{
		// New to convert unsigned int into a string
		// We will need a maximum of 10 chars to represent a 32-bit number
		// (range is 0 to 4294967295 inclusive)
		char tempBuff[11];
		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%" PRIu32,
			myUint32);
		// Add converted uint32 to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	MIOStream & MIOStream::operator << (int32_t myInt32)
	{
		// New to convert unsigned int into a string
		// We will need a maximum of 11 chars to represent a 32-bit number
		// (range is -2147483648 to 2147483647 inclusive)
		char tempBuff[12];
		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%" PRIi32,
			myInt32);
		// Add converted uint32 to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	MIOStream & MIOStream::operator << (uint64_t myUint64)
	{
		// New to convert unsigned int into a string
		// We will need a maximum of 20 chars to represent a 64-bit number
		// (range is 0 to 1.844X10^19 inclusive)
		char tempBuff[21];
		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%" PRIu64,
			myUint64);
		// Add converted uint32 to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	MIOStream & MIOStream::operator << (int64_t myInt64)
	{
		// New to convert unsigned int into a string
		// We will need a maximum of 20 chars to represent a 64-bit number
		// (range is -9.22x10^18 to 9.22x10^18 inclusive)
		char tempBuff[21];
		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%" PRIi64,
			myInt64);
		// Add converted uint32 to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	MIOStream & MIOStream::operator << (double myDouble)
	{
		// Convert double into a string
		// To represent a 64-bit IEEE double, you would need a maximum of 1079 chars to represent
		// it, crazy!!!
		// For this reason we will choose to truncate it
		//
		char tempBuff[maxNumCharsForDouble + 1];
		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%g",
			myDouble);
		// Add converted uint32 to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;

	}

} // namespace MbeddedNinja

// EOF
