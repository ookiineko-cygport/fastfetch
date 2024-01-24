#include "libc.h"

#include <_newlib_version.h>
#include <cygwin/version.h>
#include <stdio.h>


const char* ffDetectLibc(FFLibcResult* result)
{
    static char version[40] = {"\0"};

    result->name = "newlib-cygwin";

    if (version[0])
    {
        // Already populated
        result->version = version;
        return NULL;
    }

    int maj = CYGWIN_VERSION_DLL_MAJOR / 1000;
    int min = CYGWIN_VERSION_DLL_MAJOR % 1000;
    int rev = CYGWIN_VERSION_DLL_MINOR;

    snprintf(version, sizeof(version), "%d.%d.%d (Newlib " _NEWLIB_VERSION ")", maj, min, rev);

    if (version[0])
        result->version = version;
    else
        result->version = "Error formatting version string";
    return NULL;
}
