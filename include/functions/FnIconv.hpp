/*-
 * Copyright (c) 2004 - 2011 CTPP Team
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the CTPP Team nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *      FnIconv.hpp
 *
 * $CTPP$
 */
#ifndef _FN_ICONV_HPP__
#define _FN_ICONV_HPP__ 1

#include "CTPP2VMSyscall.hpp"

#ifdef ICONV_SUPPORT
#include <iconv.h>
#endif // ICONV_SUPPORT

#include "STLMap.hpp"
#include "STLString.hpp"

/**
  @file FnIconv.hpp
  @brief Virtual machine standard library function, escape value, iconv converter
*/


namespace CTPP // C++ Template Engine
{

class CDT;
class Logger;

#ifdef ICONV_SUPPORT
/**
  @class FnIconv FnIconv.hpp <FnIconv.hpp>
  @brief Iconv converter
*/
class CTPP2DECL FnIconv:
  public SyscallHandler
{
	/**
	  @brief Constructor
	*/
 	FnIconv();

	/**
	  @brief A destructor
	*/
	~FnIconv() throw();

private:
	friend class STDLibInitializer;

	/**
	  @brief Handler
	  @param aArguments - list of arguments
	  @param iArgNum - number of arguments
	  @param oCDTRetVal - return value
	  @param oLogger - logger
	  @return 0 - if success, -1 - otherwise
	*/
	INT_32 Handler(CDT            * aArguments,
	               const UINT_32    iArgNum,
	               CDT            & oCDTRetVal,
	               Logger         & oLogger);

	/**
	  @brief Get function name
	*/
	CCHAR_P GetName() const;

	/** Charsets */
	STLW::map<STLW::string, iconv_t> mIconvMap;
};

#endif // ICONV_SUPPORT

} // namespace CTPP
#endif // _FN_ICONV_HPP__
// End.
