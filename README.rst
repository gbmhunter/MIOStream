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
- Last Modified: 2014-10-12
- Version: v1.0.1.0
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



Features:

- Embedded (microcontroller) support
- Small flash/RAM memory footprint (no depedance on the C++ std::iostream class)
- Unit tests
- Doxygen-style well-documented API.
- Portability

Code Dependencies
=================

The following table lists all of MStrings dependencies.

====================== ==================== ======================================================================
Dependency             Delivery             Usage
====================== ==================== ======================================================================
<cinttypes>            C standard library   For platform agnostic printf() specifiers.
<cstdint>              C standard library   For platform agnostic fixed-width integers.
<cstdio>               C standard library   To use snprintf() for appending integers, floats and doubles to the ends of a string.
<cstring>              C standard library   For use of strlen() and strcpy().
MAssert                External module      Providing runtime safety checks against this module.
MString                External module      Provides a MString object as a internal buffer for the MIOStringStream object.
MUnitTest              External module      Framework for unit tests.
====================== ==================== ======================================================================

Issues
======

See GitHub Issues.

Limitations
===========

Nothing here yet.

Usage
=====

See the unit tests in the 'test/' directory for basic examples.
	
Changelog
=========

========= ========== ===========================================================================================
Version   Date       Comment
========= ========== ===========================================================================================
v1.0.1.0  2014-10-12 Add the capability to insert integers and floats into a MIOStream, closes #1.
v1.0.0.0  2014-10-12 Initial commit, basic MIOStream and MIOStringStream objects have been implemented with one unit test.
========= ========== ===========================================================================================