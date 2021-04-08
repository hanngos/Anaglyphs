#pragma once
#include "BMP.h"
#include "JACpp.h"

extern "C" void asmAnaglyph(BYTE * result, BYTE * LeftBMPData, BYTE * RightBMPData, int begin, int end);

ref class LibraryHandler
{
public:
	void createAnaglyph(Object^ obj);
};

