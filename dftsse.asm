

segment .data

segment .bss

segmet .text
	global _start
	extern x

	_start:

	movddup xmm0, qword[x]
	movddup xmm2, qword[x+8]
	call angulo
	fsin
	movlpd xmm1, st0
	movhpd xmm3, st0
	call angulo
	fcos
	movhpd xmm1, st0
	movlpd xmm3, st0
	mulpd xmm0, xmm1
	mulpd xmm2, xmm3
	addsubpd xmm0, xmm2






	angulo:
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