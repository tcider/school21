global		_ft_list_sort					; ft_list_sort(RDI, RSI)
											; RDI = **list, RSI = int (*cmp))

section		.text
_ft_list_sort:
			push	rbp						; we'll call user (*cmp) so
			push	rbx
			push	rdi
			push	rsi
			mov		rbp, rsp				; save stack pointers in bad case)
			cmp		rdi, 0						; **list == NULL
			je		exit
			cmp		rsi, 0
			je		exit					; (*cmp) == NULL
			mov		rdx, [rdi]				; curent head of list  = *list
			cmp		rdx, 0
			je		exit
			mov		rbx, rsi					; save (*cmp)
			xor		rcx, rcx				; flag "if sorted"
			mov		r10, rdx				; list = list.head
			jmp		while
check:
			cmp		rcx, 0
			je		exit
			xor		rcx, rcx
			mov		r10, rdx
while:
			mov		r11, [r10 + 8]			; list->next
			cmp		r11, 0
			je		check
			mov		rdi, [r10]				; args for cmp()
			mov		rsi, [r11]
			push	r10						; save r10, rcx, rdx
			push	rcx						; befor call another
			push	rdx
			call	rbx
			pop		rdx
			pop		rcx
			pop		r10
			cmp		rax, 0
			jg		swap
			mov		r10, [r10 + 8]			; list = list->next
			jmp		while
swap:
			mov		rcx, 1					; rase flag if swap
			mov		r8, [r11]
			mov		r9, [r10]
			mov		[r11], r9
			mov		[r10], r8
			jmp		while

exit:
			mov		rsp, rbp				; recover stack
			pop		rsi
			pop		rdi
			pop		rbx
			pop		rbp
			ret
