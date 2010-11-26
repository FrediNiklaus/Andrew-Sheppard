#include <windows.h>

BOOL DoesWin32MethodExist(LPCTSTR moduleName, LPCSTR methodName)
{
    HMODULE handle = GetModuleHandle(moduleName);
    if (handle == NULL)
    {
        return FALSE;
    }
    return (GetProcAddress(handle, methodName) != NULL);
}

BOOL Is64BitOperatingSystem()
{
#if defined(_WIN64)
    return TRUE;
#elif defined(_WIN32)
    BOOL bitness64 = FALSE;
    return ((DoesWin32MethodExist("kernel32.dll", "IsWow64Process") && 
        IsWow64Process(GetCurrentProcess(), &bitness64)) && bitness64);
#endif
}

extern "C" int WindowsBitness()
{
	BOOL is64bits = Is64BitOperatingSystem();

	if (is64bits)
		return 64;
	else
		return 32;
}

extern "C" int ProcessBitness()
{
#if defined(_WIN64)
	return 64;
#elif defined(_WIN32)
	return 32;
#endif
}

