//!
//! @file				IOStringStream.hpp
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

#ifndef M_IO_STREAM_IO_STRING_STREAM_H
#define M_IO_STREAM_IO_STRING_STREAM_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	class IOStringStream;
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <stdint.h>		// uint8_t, uint32_t, e.t.c
#include <iostream>

//===== USER LIBRARIES =====//
#include "MString/api/MStringApi.hpp"

//===== USER SOURCE =====//
#include "IOStringStream.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{

	//! @brief		String class designed for embedded applications.
	//! @details	Exceptions are not used.
	class IOStringStream : public IOStream
	{	
		
		public:

			//======================================================================================//
			//==================================== PUBLIC METHODS ==================================//
			//======================================================================================//

			//! @brief		Constructor.
			//! @details
			IOStringStream(){};

			//! @brief		Copy constructor.
			//! @details	Delegates to normal constructor.
			//MIOStringStream(const MIOStream &obj);

			//! @brief		Destructor.
			//! @details	Deletes memory that was allocated for the string.
			~IOStringStream(){};



			//======================================================================================//
			//============================ PUBLIC OPERATOR OVERLOAD DECLARATIONS ===================//
			//======================================================================================//

			//! \defgroup{Shift Operators}
			//! @{

			//! @brief		Allows you to append the RHS C-style string onto the LHS
			//!				string object with LHS << RHS.
			IOStringStream & operator << (const char * rhs)
			{
				// Append the C-style string onto the end
				this->myString.Append(rhs);
				return (*this);
			}

			IOStringStream & operator << (uint8_t myUint8)
			{
				IOStream::operator << (myUint8);
				return *this;
			}

			//! @brief		Operator overload for int8_t. Appends integer onto the end of the string.
			IOStringStream & operator << (int8_t myInt8)
			{
				IOStream::operator << (myInt8);
				return *this;
			}

			//! @brief		Operator overload for uint16_t. Appends unsigned integer onto the end of the string.
			IOStringStream & operator << (uint16_t myUint16)
			{
				IOStream::operator << (myUint16);
				return *this;
			}

			//! @brief		Operator overload for int16_t. Appends integer onto the end of the string.
			IOStringStream & operator << (int16_t myInt16)
			{
				IOStream::operator << (myInt16);
				return *this;
			}

			//! @brief		Operator overload for uint32_t. Appends unsigned integer onto the end of the string.
			IOStringStream & operator << (uint32_t myUint32)
			{
				IOStream::operator << (myUint32);
				return *this;
			}

			//! @brief		Operator overload for int32_t. Appends integer onto the end of the string.
			IOStringStream & operator << (int32_t myInt32)
			{
				IOStream::operator << (myInt32);
				return *this;
			}

			//! @brief		Operator overload for uint64_t. Appends unsigned integer onto the end of the string.
			IOStringStream & operator << (uint64_t myUint64)
			{
				IOStream::operator << (myUint64);
				return *this;
			}

			//! @brief		Operator overload for int64_t. Appends integer onto the end of the string.
			IOStringStream & operator << (int64_t myInt64)
			{
				IOStream::operator << (myInt64);
				return *this;
			}

			//! @brief		Operator overload for double. Appends double onto the end of the string.
			IOStringStream & operator << (double myDouble)
			{
				IOStream::operator << (myDouble);
				return *this;
			}

			//! @}

			//======================================================================================//
			//================================= PUBLIC VARIABLES ===================================//
			//======================================================================================//

			//! @brief		This is the internal string object that the MIOStringStream reads and writes to.
			MString myString;

		protected:

			//======================================================================================//
			//=================================== PROTECTED METHODS ================================//
			//======================================================================================//
			
			

			//===================================================================================//
			//=============================== PROTECTED VARIABLES ===============================//
			//===================================================================================//

			// none


		private:

			//======================================================================================//
			//=================================== PRIVATE METHODS ==================================//
			//======================================================================================//
			
			// none
			
			//======================================================================================//
			//================================== PRIVATE VARIABLES =================================//
			//======================================================================================//


		
	}; // class IOStringStream

} // namespace MbeddedNinja

#endif	// #ifndef M_IO_STREAM_IO_STRING_STREAM_H

// EOF
