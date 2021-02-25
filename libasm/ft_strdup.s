global		_ft_strdup						; ft_strdup(RDI)
extern		_ft_strlen
extern		_malloc
extern		_ft_strcpy

section		.text
_ft_strdup:
			cmp		rdi, 0
			je		error
			push	rsi						; i'll use RSI so save it
			push	rdi						; save our arg to
			call	_ft_strlen				; in RAX now str length
			inc		rax						; + 1 for null terminator
			mov		rdi, rax				; set length as malloc arg
			call	_malloc					; in RAX we have adr of heap
			cmp		rax, 0					; if malloc returns NULL
			je		exit
			mov		rdi, rax				; set dest for strcpy
			mov		rsi, [rsp]				; set source from our RDI in stack
			call	_ft_strcpy				; in RAX we have dest as needed
exit:
			pop		rdi						; restore stack and RSI RDI
			pop		rsi
			ret
error:
			xor		rax, rax
			ret
