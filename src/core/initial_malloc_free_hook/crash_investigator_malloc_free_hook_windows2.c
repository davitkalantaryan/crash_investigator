//
// file:		crash_investigator_malloc_free_hook_windows2.c
// path:		src/core/crash_investigator_malloc_free_hook_windows2.c
// created by:	Davit Kalantaryan (davit.kalataryan@desy.de)
// created on:	2021 Nov 24
//

#if defined(_WIN32)

#include <crash_investigator/crash_investigator_internal_header.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>



CPPUTILS_BEGIN_C

CPPUTILS_DLL_PRIVATE void  free_default(void* a_ptr){HeapFree(GetProcessHeap(), 0, a_ptr);}
CPPUTILS_DLL_PRIVATE void* malloc_default(size_t a_count) { return HeapAlloc(GetProcessHeap(), 0, CPPUTILS_STATIC_CAST(SIZE_T, a_count));}
CPPUTILS_DLL_PRIVATE void* realloc_default(void* a_ptr, size_t a_count) { return HeapReAlloc(GetProcessHeap(), 0, a_ptr, CPPUTILS_STATIC_CAST(SIZE_T, a_count));}
CPPUTILS_DLL_PRIVATE void* calloc_default(size_t a_nmemb, size_t a_size) {
	const size_t unCount = a_nmemb * a_size;
	return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, CPPUTILS_STATIC_CAST(SIZE_T, unCount));
}


#define CRASH_INVEST_INTERFACE_NOT_KNOWN
CRASH_INVEST_INTERFACE_NOT_KNOWN CPPUTILS_DLL_PRIVATE void _windows_crt_all_unknown_functionsWeak(void) {}
#pragma comment(linker, "/alternatename:_RTC_InitBase=_windows_crt_all_unknown_functionsWeak")
#pragma comment(linker, "/alternatename:_RTC_Shutdown=_windows_crt_all_unknown_functionsWeak")
#pragma comment(linker, "/alternatename:_DllMainCRTStartup=_windows_crt_all_unknown_functionsWeak")
#pragma comment(linker, "/alternatename:__security_check_cookie=_windows_crt_all_unknown_functionsWeak")


CPPUTILS_END_C


#endif  // #ifdef _WIN32
