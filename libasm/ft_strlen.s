global		_ft_strlen						; ft_strlen(RDI)

section		.text
_ft_strlen:
			xor		rax, rax				; as iterator is length so in RAX
while:
			cmp		rdi, 0					; if str == NULL
			je		exit
			cmp		byte [rdi + rax], 0
			je		exit
			inc		rax
			jmp		while
exit:
			ret								; return result in RAX
