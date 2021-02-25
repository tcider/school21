global		_ft_list_remove_if				; ft_list_remove_i(RDI, RSI, RDX)
extern		_free							; RSI *data_ref, RDX= int (*cmp))

section		.text
_ft_list_remove_if:
			push	rsi						; we should save them after call
			push	rdi
			push	rdx						; not for caller but for us
			cmp		rdi, 0
			je		exit
			cmp		rdx, 0
			je		exit
			mov		r12, [rdi]				; *begin_list
			xor		r10, r10				; *prev_list
while:
			cmp		r12, 0
			je		exit
			mov		rdx, [rsp]				; restore rdx in case its destroyed
			mov		rsi, [rsp + 16]			; get rsi from stack too
			mov		rdi, [r12]				; prepare args for cmp, RSI same
			push	r10
			push	r12
			call	rdx
			pop		r12
			pop		r10
			cmp		rax, 0
			jne		next
			mov		r11, [r12 + 8]
			mov		rdi, r12				; free(list)
			push	r10
			push	r11
			call	_free
			pop		r11
			pop		r10
			cmp		r10, 0
			je		head
			mov		[r10 + 8], r11
iteration:
			mov		r12, r11
			jmp		while
head:		
			pop		rdx
			pop		rdi
			mov		[rdi], r11
			push	rdi
			push	rdx
			jmp		iteration
next:
			mov		r10, r12
			mov		r12, [r12 + 8]
			jmp		while
exit:
			pop		rdx
			pop		rdi
			pop		rsi
			ret
