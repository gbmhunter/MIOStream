//!
//! @file				OStream.cpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-10-12
//! @last-modified		2014-10-29
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
#include "../include/OStream.hpp"


namespace MbeddedNinja
{

	//! @brief		The maximum number of characters used when shifting a double onto a string.
	//! @details	Determines the size of the temporary buffer created on the stack when adding
	//!				a double to a string via the '<<' operator.
	constexpr uint16_t maxNumCharsForDouble = 20;

	void OStream::SetPrecision(uint8_t precision)
	{
		// Save the precision in internal variable
		this->precision = precision;
	}

	OStream & OStream::operator << (uint8_t myUint8)
	{
		// New to convert unsigned 8-bit int into a string
		// We will need a maximum of 3 chars to represent a 8-bit unsigned int
		// (range is 0 to 255 inclusive)
		uint8_t tempBuffLenth;
		if(this->precision <= 3)
		{
			tempBuffLenth = 4;
		}
		else
		{
			tempBuffLenth = this->precision + 1;
		}
		char tempBuff[tempBuffLenth];

		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%.*" PRIu8,
			this->precision,
			myUint8);
		// Add converted number to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	OStream & OStream::operator << (int8_t myInt8)
	{
		// Need to convert signed 8-bit int into a string
		// We will need a maximum of 4 chars to represent a 8-bit signed number
		// (range is -127 to 127 inclusive)
		uint8_t tempBuffLenth;
		if(this->precision <= 4)
		{
			tempBuffLenth = 5;
		}
		else
		{
			tempBuffLenth = this->precision + 1;
		}
		char tempBuff[tempBuffLenth];

		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%.*" PRIi8,
			this->precision,
			myInt8);
		// Add converted number to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	OStream & OStream::operator << (uint16_t myUint16)
	{
		// New to convert unsigned 16-bit int into a string
		// We will need a maximum of 5 chars to represent a 16-bit unsigned number
		// (range is 0 to 65535 inclusive)
		uint8_t tempBuffLenth;
		if(this->precision <= 5)
		{
			tempBuffLenth = 6;
		}
		else
		{
			tempBuffLenth = this->precision + 1;
		}
		char tempBuff[tempBuffLenth];

		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%.*" PRIu16,
			this->precision,
			myUint16);
		// Add converted number to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	OStream & OStream::operator << (int16_t myInt16)
	{
		// New to convert signed 16-bit int into a string
		// We will need a maximum of 6 chars to represent a 16-bit signed number
		// (range is -32767 to 32767 inclusive)
		uint8_t tempBuffLenth;
		if(this->precision <= 6)
		{
			tempBuffLenth = 7;
		}
		else
		{
			tempBuffLenth = this->precision + 1;
		}
		char tempBuff[tempBuffLenth];

		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%.*" PRIi16,
			this->precision,
			myInt16);
		// Add converted number to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	OStream & OStream::operator << (uint32_t myUint32)
	{
		// New to convert unsigned int into a string
		// We will need a maximum of 10 chars to represent a 32-bit number
		// (range is 0 to 4294967295 inclusive)
		uint8_t tempBuffLenth;
		if(this->precision <= 10)
		{
			tempBuffLenth = 11;
		}
		else
		{
			tempBuffLenth = this->precision + 1;
		}
		char tempBuff[tempBuffLenth];

		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%.*" PRIu32,
			this->precision,
			myUint32);
		// Add converted uint32 to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	OStream & OStream::operator << (int32_t myInt32)
	{
		// Need to convert 32-bit int into a string
		// We will need a maximum of 11 chars to represent a 32-bit number
		// (range is -2147483648 to 2147483647 inclusive)
		uint8_t tempBuffLenth;
		if(this->precision <= 11)
		{
			tempBuffLenth = 12;
		}
		else
		{
			tempBuffLenth = this->precision + 1;
		}
		char tempBuff[tempBuffLenth];

		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%.*" PRIi32,
			this->precision,
			myInt32);
		// Add converted int32 to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	OStream & OStream::operator << (uint64_t myUint64)
	{
		// Need to convert unsigned 64-bit int into a string
		// We will need a maximum of 20 chars to represent a 64-bit number
		// (range is 0 to 1.844X10^19 inclusive)
		uint8_t tempBuffLenth;
		if(this->precision <= 20)
		{
			tempBuffLenth = 21;
		}
		else
		{
			tempBuffLenth = this->precision + 1;
		}
		char tempBuff[tempBuffLenth];

		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%.*" PRIu64,
			this->precision,
			myUint64);
		// Add converted uint64 to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	OStream & OStream::operator << (int64_t myInt64)
	{
		// New to convert unsigned int into a string
		// We will need a maximum of 20 chars to represent a 64-bit number
		// (range is -9.22x10^18 to 9.22x10^18 inclusive)
		uint8_t tempBuffLenth;
		if(this->precision <= 20)
		{
			tempBuffLenth = 21;
		}
		else
		{
			tempBuffLenth = this->precision + 1;
		}
		char tempBuff[tempBuffLenth];

		snprintf(
			tempBuff,
			sizeof(tempBuff),
			"%.*" PRIi64,
			this->precision,
			myInt64);
		// Add converted int64 to end of string
		(*this) << tempBuff;

		// Return reference for chaining purposes
		return *this;
	}

	OStream & OStream::operator << (double myDouble)
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
