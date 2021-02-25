global		_ft_strcmp						; ft_strcmp(RDI, RSI)

section		.text
_ft_strcmp:
			xor		rcx, rcx	
while:
			cmp		rdi, 0
			je		error1
			cmp		rsi, 0
			je		error2
			mov		dl, [rdi + rcx]			; for dest use RDX instead RAX
			mov		al, [rsi + rcx]			; so it's easier movsx RAX, DL
			cmp		dl, 0
			je		finish
			cmp		al, 0
			je		finish
			cmp		al, dl
			jne		finish
			inc		rcx
			jmp		while
finish:
			sub		dl, al
			movsx	rax, dl					; expand sign byte on all RAX
			ret
error1:
			cmp		rsi, 0
			je		error3
			mov		dl, [rsi]
			movsx	rax, dl
			ret
error2:
			mov		dl, [rdi]
			movsx	rax, dl
			ret
error3:
			xor		rax, rax
			ret
			
