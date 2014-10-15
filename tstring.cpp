#include "tstring.h"
#include <memory>

namespace win{
	std::string to_string(const TCHAR* source, UINT codepage) {
#ifdef  UNICODE
		int len = WideCharToMultiByte(codepage, WC_SEPCHARS, source, -1, NULL, 0, NULL, NULL);
		auto output = std::unique_ptr<char[]>(new char[len]);

		WideCharToMultiByte(codepage, WC_SEPCHARS, source, -1, output.get(), len, NULL, NULL);

		std::string str = output.get();
		return str;
#else
		return source;
#endif
	}

	tstring to_tstring(const char * source, UINT codepage) {
#ifdef  UNICODE
		int len = MultiByteToWideChar(codepage, MB_PRECOMPOSED, source, -1, NULL, 0);
		auto output = std::unique_ptr<wchar_t[]>(new wchar_t[len]);

		MultiByteToWideChar(codepage, MB_PRECOMPOSED, source, -1, output.get(), len);

		tstring str = output.get();
		return str;
#else
		return source;
#endif
	}
}