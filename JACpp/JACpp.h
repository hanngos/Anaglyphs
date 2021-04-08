#pragma once

#ifdef JACPP_EXPORTS
#define APP __declspec(dllexport)
#else
#define APP __declspec(dllimport)
#endif

extern "C" APP void cppAnaglyph(BYTE * result, BYTE * LeftBMPData, BYTE * RightBMPData, int begin, int end);
