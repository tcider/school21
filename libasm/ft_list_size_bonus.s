global		_ft_list_size					; ft_list_size(RDI)

section		.text
_ft_list_size:
			push	rdi						; save head of list
			xor		rax, rax				; not RCX to have len in return
count:
			cmp		rdi, 0
			je		exit
			inc		rax
			mov		rdi, [rdi + 8]			; list = list->next
			jmp		count
exit:
			pop		rdi
			ret
