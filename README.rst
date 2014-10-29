=========
MIOStream
=========

------------------------------------------------------------------------------------------------
A microcontroller friendly C++ IO stream object specifically designed for embedded applications.
------------------------------------------------------------------------------------------------

.. image:: https://api.travis-ci.org/mbedded-ninja/MIOStream.png?branch=master   
	:target: https://travis-ci.org/mbedded-ninja/MIOStream

- Author: gbmhunter <gbmhunter@gmail.com> (www.mbedded.ninja)
- First Ever Commit: 2014-10-12
- Last Modified: 2014-10-29
- Version: v1.1.0.0
- Company: mbedded.ninja
- Project: MToolkit Module
- Language: C++
- Compiler: GCC	
- uC Model: Ay
- Computer Architecture: Any
- Operating System: Any
- Documentation Format: Doxygen
- License: GPLv3

Description
===========

A microcontroller friendly C++ IO stream object specifically designed for embedded applications.

Features:

- Embedded (microcontroller) support
- Small flash/RAM memory footprint (no depedance on any C++ standard libraries, including the C++ :code:`std::iostream` class)
- Unit tests
- Doxygen-style well-documented API.
- Portability

Code Dependencies
=================

The following table lists all of MStrings dependencies.

====================== ==================== ======================================================================
Dependency             Delivery             Usage
====================== ==================== ======================================================================
MAssert                External module      Providing runtime safety checks against this module.
MString                External module      Provides a MString object as a internal buffer for the MIOStringStream object.
MUnitTest              External module      Framework for unit tests.
====================== ==================== ======================================================================

Issues/Bugs/Feature Requests
============================

See GitHub Issues.

Example
=======

::

	#include "../api/MIOStreamApi.hpp"				// OStream
	#include "../port/StdOStream/StdOStream.hpp"	// StdOStream
	
	using namespace MbeddedNinja;
	
	int main()
	{
		// Lets create a StdOStream and pass it std::cout
		StdOStream myStdOStream(&std::cout);
		
		myStdOStream << "This should display on std::cout!\r\n";
	}		

See the unit tests in the 'test/' directory for more examples.
	
Changelog
=========

========= ========== ===========================================================================================
Version   Date       Comment
========= ========== ===========================================================================================
v1.1.0.0  2014-10-29 Added an implementation of OStream which used std::ostream as it's output and added example to README, closes #7. Added ability to specify the number of decimal places for a IOStream, closes #6. Dropped the 'I' from 'IOStream' and 'IOStringStream' as they are both output streams only, closes #8.
v1.0.2.0  2014-10-29 Fixed code dependencies section in the README, still has information about MString in there, closes #4. Dropped the 'M' from the classes MIOStream and MIOStringStream, closes #5.
v1.0.1.0  2014-10-12 Add the capability to insert integers and floats into a MIOStream, closes #1.
v1.0.0.0  2014-10-12 Initial commit, basic MIOStream and MIOStringStream objects have been implemented with one unit test.
========= ========== ===========================================================================================