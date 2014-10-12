//!
//! @file				MIOStringStream.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-10-12
//! @last-modified		2014-10-12
//! @brief
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef M_IO_STREAM_M_IO_STRING_STREAM_H
#define M_IO_STREAM_M_IO_STRING_STREAM_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	class MIOStream;
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <cstdint>		// uint8_t, uint32_t, e.t.c
#include <iostream>

//===== USER LIBRARIES =====//
#include "MString/api/MStringApi.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{

	//! @brief		String class designed for embedded applications.
	//! @details	Exceptions are not used.
	class MIOStringStream : public MIOStream
	{	
		
		public:

			//======================================================================================//
			//==================================== PUBLIC METHODS ==================================//
			//======================================================================================//

			//! @brief		Constructor.
			//! @details
			MIOStringStream(){};

			//! @brief		Copy constructor.
			//! @details	Delegates to normal constructor.
			//MIOStringStream(const MIOStream &obj);

			//! @brief		Destructor.
			//! @details	Deletes memory that was allocated for the string.
			~MIOStringStream(){};



			//======================================================================================//
			//============================ PUBLIC OPERATOR OVERLOAD DECLARATIONS ===================//
			//======================================================================================//

			//! \defgroup{Shift Operators}
			//! @{

			//! @brief		Allows you to append the RHS C-style string onto the LHS
			//!				string object with LHS << RHS.
			MIOStringStream & operator << (const char * rhs)
			{
				// Append the C-style string onto the end
				this->myString.Append(rhs);
			}
/*
			//! @brief		Allows you to append the RHS string object onto the LHS
			//!				string object with LHS << RHS.
			MIOStringStream & operator << (const MString & rhs);

			//! @brief		Operator overload for uint8_t. Appends unsigned integer onto the end of the string.
			MIOStringStream & operator << (uint8_t myUint16);

			//! @brief		Operator overload for int8_t. Appends integer onto the end of the string.
			MIOStringStream & operator << (int8_t myInt16);

			//! @brief		Operator overload for uint16_t. Appends unsigned integer onto the end of the string.
			MIOStringStream & operator << (uint16_t myUint16);

			//! @brief		Operator overload for int16_t. Appends integer onto the end of the string.
			MIOStringStream & operator << (int16_t myInt16);

			//! @brief		Operator overload for uint32_t. Appends unsigned integer onto the end of the string.
			MIOStringStream & operator << (uint32_t myUint32);

			//! @brief		Operator overload for int32_t. Appends integer onto the end of the string.
			MIOStringStream & operator << (int32_t myInt32);

			//! @brief		Operator overload for uint64_t. Appends unsigned integer onto the end of the string.
			MIOStringStream & operator << (uint64_t myUint64);

			//! @brief		Operator overload for int64_t. Appends integer onto the end of the string.
			MIOStringStream & operator << (int64_t myInt64);

			//! @brief		Operator overload for double. Appends double onto the end of the string.
			MIOStringStream & operator << (double myDouble);*/

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


		
	}; // class MIOStringStream

} // namespace MbeddedNinja

#endif	// #ifndef M_IO_STREAM_M_IO_STRING_STREAM_H

// EOF
