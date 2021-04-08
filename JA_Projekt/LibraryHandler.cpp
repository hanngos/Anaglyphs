#include "LibraryHandler.h"

void LibraryHandler::createAnaglyph(Object^ obj)
{

	Tuple<bool, BMP^, BMP^, int, int>^ params = (Tuple<bool, BMP^, BMP^, int, int>^) obj;

	if (params->Item1 == true) {
		cppAnaglyph(params->Item2->result, params->Item2->BMPData, params->Item3->BMPData, params->Item4, params->Item5);
	}
	else {
		asmAnaglyph(params->Item2->result, params->Item2->BMPData, params->Item3->BMPData, params->Item4, params->Item5);
	}
}
