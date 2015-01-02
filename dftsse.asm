segment .data

segment .bss

segmet .text
	global dftsse
	extern val_complex
	extern res_complex

	dftsse:
		mov ecx, 1024
		LoopJ:
		mov ebx, ecx 

			mov ecx, 1024
			mov eax, 0
			LoopK:
				movddup xmm0, [val_complex+eax]
				movddup xmm2, [val_complex+eax+8]
				call Angulo
				fsin
				movlpd xmm1, st0
				movhpd xmm3, st0
				call Angulo
				fcos
				movhpd xmm1, st0
				movlpd xmm3, st0
				mulpd xmm0, xmm1
				mulpd xmm2, xmm3
				addsubpd xmm0, xmm2
				
				movapd xmm1, [res_complex+eax]
				addpd xmm0, xmm1
				movapd [res_complex+eax], xmm0

				add eax, 16
				loop LoopK

		mov ecx, ebx
		loop LoopJ






		Angulo:
			finit
			fild 1024
			fldpi
			fldpi
			faddp
			fild -1
			fmulp
			fdivp
			fld qword[j]
			fmulp
			fld qword[k]
			fmulp
			ret