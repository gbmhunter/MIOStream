//!
//! @file				OStream.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-10-12
//! @last-modified		2014-10-29
//! @brief
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef M_IO_STREAM_O_STREAM_H
#define M_IO_STREAM_O_STREAM_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	class OStream;
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <cstdint>		// uint8_t, uint32_t, e.t.c
#include <cstdio>		// snprintf()
#include <cinttypes>	// PRIu8, e.t.c

//! @debug
#include <iostream>

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{

	//! @brief		String class designed for embedded applications.
	//! @details	Exceptions are not used.
	class OStream
	{	
		
		public:

		static constexpr uint8_t defaultPrecision = 1;

		//======================================================================================//
		//==================================== PUBLIC METHODS ==================================//
		//======================================================================================//

		//! @brief		Copy constructor.
		//! @details	Delegates to normal constructor.
		//MIOStream(const MIOStream &obj);



		//! @brief		Destructor.
		//! @details	Deletes memory that was allocated for the string.
		virtual ~OStream(){};

		//! @brief		Sets the precision for the IO stream.
		void SetPrecision(uint8_t precision);


		//======================================================================================//
		//============================ PUBLIC OPERATOR OVERLOAD DECLARATIONS ===================//
		//======================================================================================//

		//! \defgroup{Shift Operators}
		//! @{

		//! @brief		Allows you to append the RHS C-style string onto the IOStream. All other shift-operators first convert to a string and then use this method.
		//! @details	This method, unlike the other shift-operators, is specific to the underlying buffer used.
		virtual OStream & operator << (const char * rhs) = 0;

		//! @brief		Operator overload for uint8_t. Appends unsigned integer onto the end of the string.
		OStream & operator << (uint8_t myUint8);

		//! @brief		Operator overload for int8_t. Appends integer onto the end of the string.
		OStream & operator << (int8_t myInt16);

		//! @brief		Operator overload for uint16_t. Appends unsigned integer onto the end of the string.
		OStream & operator << (uint16_t myUint16);

		//! @brief		Operator overload for int16_t. Appends integer onto the end of the string.
		OStream & operator << (int16_t myInt16);

		//! @brief		Operator overload for uint32_t. Appends unsigned integer onto the end of the string.
		OStream & operator << (uint32_t myUint32);

		//! @brief		Operator overload for int32_t. Appends integer onto the end of the string.
		OStream & operator << (int32_t myInt32);

		//! @brief		Operator overload for uint64_t. Appends unsigned integer onto the end of the string.
		OStream & operator << (uint64_t myUint64);

		//! @brief		Operator overload for int64_t. Appends integer onto the end of the string.
		OStream & operator << (int64_t myInt64);

		//! @brief		Operator overload for double. Appends double onto the end of the string.
		OStream & operator << (double myDouble);

		//! @}

		//======================================================================================//
		//================================= PUBLIC VARIABLES ===================================//
		//======================================================================================//


		protected:

		//======================================================================================//
		//=================================== PROTECTED METHODS ================================//
		//======================================================================================//

		//! @brief		Constructor. Protected to enforce inheritance.
		//! @details
		OStream() :
			// Default precision is one
			precision(defaultPrecision)
		{};

		//======================================================================================//
		//================================== PROTECTED VARIABLES ===============================//
		//======================================================================================//

		// none


		private:

		//======================================================================================//
		//=================================== PRIVATE METHODS ==================================//
		//======================================================================================//

		// none

		//======================================================================================//
		//================================== PRIVATE VARIABLES =================================//
		//======================================================================================//

		//! @brief		The current precision of the IOStream when printing numbers. Set with SetPrecision().
		uint8_t precision;
		
	}; // class OStream

} // namespace MbeddedNinja

#endif	// #ifndef M_IO_STREAM_O_STREAM_H

// EOF
