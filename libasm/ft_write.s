global		_ft_write						; ft_write(RDI, RSI, RDX)
extern		___error

section		.text
_ft_write:
			mov		rax, 0x2000004
			syscall
			jc		error					; if syscall ret err then CF=1
			ret
error:
			push	rax						; save our error num
			call 	___error				; in RAX now we have errno addres
			pop		qword [rax]				; write our error num to errno
			mov		rax, -1					; ft_write should return -1 if error
			ret
