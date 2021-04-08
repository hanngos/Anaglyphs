//Anaglify, Kwapieñ Julia, Informatyka SSI 2020/21 5 semestr
//Program do tworzenia anaglifów

#include "pch.h"
#include "JACpp.h"


/*void asmAnaglyph(BYTE* result, BYTE* LeftBMPData, BYTE* RightBMPData, int begin, int end);
Funckja tworz¹ca anaglif poprzez wymno¿enie macierzy RGB przez macierz odpowiedni¹ dla obrazka(LEFT, RIGHT)
BYTE * result - wskaŸnik na tablicê wynikow¹
BYTE * LeftBMPData - wskaŸnik na tablicê z danymi RGB pobranymi z lewego obrazu
BYTE * RightBMPData - wskaŸnik na tablicê z danymi RGB pobranymi z prawego obrazu
int begin - pocz¹tek pêtli(od którego miejsca w obrazie program ma zacz¹æ pêtle) - wynika z w¹tków
int end - przeskok(ile pikseli zostanie przetworzonych)*/
APP void cppAnaglyph(BYTE* result, BYTE* LeftBMPData, BYTE* RightBMPData, int begin, int end)
{
	for (int s = begin; s < begin + end; s += 3) {
		result[s + 0] = RightBMPData[s + 0];
		result[s + 1] = RightBMPData[s + 1];
		result[s + 2] = LeftBMPData[s + 2];
	}

  /*0 0 0	B
	0 0 0	G
	0 0 1	R*/

	/*BYTE LEFT[9] = { 0,0,0,0,0,0,0,0,1 };
	BYTE RIGHT[9] = { 1,0,0,0,1,0,0,0,0 };

	for (int s = begin; s < begin + end; s += 3) {
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				result[s + i] += LEFT[i * 3 + k] * LeftBMPData[s + k];
				result[s + i] += RIGHT[i * 3 + k] * RightBMPData[s + k];
			}
		}
	}*/

}
