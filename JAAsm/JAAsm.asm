;Anaglify, Kwapieñ Julia, Informatyka SSI 2020/21 5 semestr
;Program do tworzenia anaglifów

.DATA
LEFT db 0,0,0,0,0,0,0,0,1
RIGHT db 1,0,0,0,1,0,0,0,0

.CODE

;void asmAnaglyph(BYTE * result, BYTE * LeftBMPData, BYTE * RightBMPData, int begin, int end);
;Funckja tworz¹ca anaglif poprzez wymno¿enie macierzy RGB przez macierz odpowiedni¹ dla obrazka (LEFT, RIGHT)
;RCX - BYTE * result - wskaŸnik na tablicê wynikow¹
;RDX - BYTE * LeftBMPData - wskaŸnik na tablicê z danymi RGB pobranymi z lewego obrazu
;R8 - BYTE * RightBMPData - wskaŸnik na tablicê z danymi RGB pobranymi z prawego obrazu
;R9 - int begin - pocz¹tek pêtli (od którego miejsca w obrazie program ma zacz¹æ pêtle) - wynika z w¹tków
;stos - int end - przeskok (ile pikseli zostanie przetworzonych)

asmAnaglyph PROC

;	for (int s = begin; s < begin + end; s += 3) {
;		for (int i = 0; i < 3; i++) {
;			for (int k = 0; k < 3; k++) {
;				result[s + i] = result[s + i] + LEFT[i * 3 + k] * LeftBMPData[s + k];
;				result[s + i] = result[s + i] + RIGHT[i * 3 + k] * RightBMPData[s + k];
;			}
;		}
;	}

	push r10
	xor r10, r10
	mov r10, [rsp + 48] ;r10 = end
	add r10, r9 ;r10 = begin + end
	push rax
	xor rax, rax
	push rbx
	push r11
	push r12
	push r13

L1:
	xor r11, r11 ;r11 = i
	
	L2: 
		xor r13, r13 ;rcx = k
		
		L3:
			xor rbx, rbx
			
			;result[s + i] = result[s + i] + LEFT[i * 3 + k] * LeftBMPData[s + k]
			mov r12, r11 ;r12 = i
			imul r12, 3 ;r12 = i * 3
			add r12, r13 ;r12 = i * 3 + k
			mov rax, offset LEFT 
			mov bl, [rax + r12]
			movd xmm0, ebx ;LEFT[i * 3 + k]
			mov r12, r13 ;r12 = k
			add r12, r9 ;r12 = k + s
			mov bl, [rdx + r12]
			movd xmm1, ebx ;LeftBMPData[s + k]
			cvtdq2ps xmm0, xmm0 ;zamiana rej xmm0 na zmiennoprzecinkow¹
			cvtdq2ps xmm1, xmm1 ;zamiana rej xmm1 na zmiennoprzecinkow¹
			mulss xmm0, xmm1 ;LEFT[i * 3 + k] * LeftBMPData[s + k]
			mov r12, r9 ;r12 = s
			add r12, r11 ; s + i
			mov bl, [rcx + r12] ;result[s + i]
			movd xmm2, ebx
			cvtdq2ps xmm2, xmm2 ;zamiana rej xmm2 na zmiennoprzecinkow¹
			paddd xmm0, xmm2 ;result[s + i] + LEFT[i * 3 + k] * LeftBMPData[s + k]
			cvtss2si ebx, xmm0 ;zamiana wartoœci typu zmiennoprzecinkowego na ca³kowity
			mov [rcx + r12], bl ;result[s + i] = result[s + i] + LEFT[i * 3 + k] * LeftBMPData[s + k]

			;result[s + i] = result[s + i] + RIGHT[i * 3 + k] * RightBMPData[s + k]
			mov r12, r11 ;r12 = i
			imul r12, 3 ;r12 = i * 3
			add r12, r13 ;r12 = i * 3 + k
			mov rax, offset RIGHT
			mov bl, [rax + r12]
			movd xmm0, ebx ;RIGHT[i * 3 + k]
			mov r12, r13 ;r12 = k
			add r12, r9 ;r12 = k + s
			mov bl, [r8 + r12]
			movd xmm1, ebx ;RightBMPData[s + k]
			cvtdq2ps xmm0, xmm0 ;zamiana rej xmm0 na zmiennoprzecinkow¹
			cvtdq2ps xmm1, xmm1 ;zamiana rej xmm1 na zmiennoprzecinkow¹
			mulss xmm0, xmm1 ;RIGHT[i * 3 + k] * RightBMPData[s + k]
			mov r12, r9 ;r12 = s
			add r12, r11 ;s + i
			mov bl, [rcx + r12] ;result[s + i]
			movd xmm2, ebx
			cvtdq2ps xmm2, xmm2 ;zamiana rej xmm2 na zmiennoprzecinkow¹
			paddd xmm0, xmm2 ;result[s + i] + RIGHT[i * 3 + k] * RightBMPData[s + k]
			cvtss2si ebx, xmm0 ;zamiana wartoœci typu zmiennoprzecinkowego na ca³kowity
			mov [rcx + r12], bl ;result[s + i] = result[s + i] + RIGHT[i * 3 + k] * RightBMPData[s + k]

			inc r13
			cmp r13, 3
			jl L3

		inc r11 
		cmp r11, 3
		jl L2

	add r9, 3 ;r9 = s
	cmp r9, r10
	jl L1

EndProc:
	pop r13
	pop r12
	pop r11
	pop rbx
	pop rax
	pop r10
	ret
asmAnaglyph ENDP

END