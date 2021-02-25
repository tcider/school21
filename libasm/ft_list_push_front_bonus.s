global		_ft_list_push_front			; args(RDI-**begin_list, RSI-*data)
extern		_malloc

section		.text
_ft_list_push_front:
			push	rdi					; save our args
			push	rsi
			mov		rdi, 16				; struct s_list size
			call	_malloc
			cmp		rax, 0
			je		err
			pop		rsi
			mov		[rax], rsi			; *data is going first in list
			pop		rdi					; restore **begin_list
			mov		rdx, [rdi]			; save *begin_list in temp rdx
			mov		[rax + 8], rdx		; new->next = begin_list
			mov		[rdi], rax			; *begin_list = new
			ret
err:
			pop		rsi
			pop		rdi					; recover stack
			ret
