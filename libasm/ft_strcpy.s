global		_ft_strcpy						; ft_strcpy(RDI, RSI)

section 	.text
_ft_strcpy:
			xor		rcx, rcx				; standart iterator
while:
			cmp		rdi, 0
			je		error
			cmp		rsi, 0
			je		error
			mov		dl, [rsi + rcx]			; didn't null the RDX, use only DL
			cmp		dl, 0
			je		finish
			mov		[rdi + rcx], dl
			inc		rcx
			jmp		while
finish:
			mov		byte [rdi + rcx], 0		; terminating destination
			mov		rax, rdi				; we should return destination
			ret
error:
			xor		rax, rax
			ret
