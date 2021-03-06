#pragma once
#include <fstream>
#include <regex>
#include <string>
#include <cstddef>
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;


ref class BMP
{
public:
    int width, height, size;
    BYTE* result;
    BYTE* BMPData, * InfoHeader;
    const char* filename;
    BMP();
    String^ readBMP(const char* filename);
    void writeBMP();
    void clear();
};

