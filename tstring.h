#pragma once
/*!
@file tstring.h
@brief TCHAR関連
@author takamoto
@date 14/10/15
*/

#include <string>
#include <tchar.h>
#include <Windows.h>

/*!
@namespace win
@brief Windows独自実装に関するクラスや関数を含む名前空間
*/
namespace win
{
	typedef std::basic_string<TCHAR> tstring;

	std::string to_string(const TCHAR* source, UINT codepage = CP_THREAD_ACP);
	tstring to_tstring(const char * source, UINT codepage = CP_THREAD_ACP);
}
