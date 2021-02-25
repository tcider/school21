global		_ft_atoi_base					; ft_atoi_base(RDI-str, RSI-base)
extern		_ft_strlen

section		.text
_ft_atoi_base:
			push	rsi						; save our args
			push	rdi
			mov		rdi, rsi				; set arg for strlen
			call	_ft_strlen
			cmp		rax, 2					; if base.len < 2 then exit
			jb		exit
			xor		rcx, rcx				; null the iterator i
			mov		r10, rax				; r10 = base size
check_base:									; while base[i]
			mov		dl, [rsi + rcx]			; get char from base
			cmp		dl, 0					; finish hile
			je		main
			cmp		dl, 43					; char == '+'
			je		exit
			cmp		dl, 45					; char == '-'
			je		exit
			cmp		dl, 33					; char < 33
			jb		exit
			cmp		dl, 126					; char > 126
			ja		exit
			inc		rcx						; i++
			mov		r11, rcx				; j
inwhile:		
			mov		al, [rsi + r11]			; while base[j]
			cmp		al, 0					; finish while
			je		check_base
			cmp		dl, al
			je		exit
			inc		r11
			jmp		inwhile
main:
			pop		rdi						; get our str
			xor		rcx, rcx
			xor		rax, rax				; our sum = 0 at start
skip_space:
			mov		dl, [rdi + rcx]
			cmp		dl, 0
			je		exit2
			cmp		dl, 9					; == '\t'
			je		increment
			cmp		dl, 10					; == '\n'
			je		increment
			cmp		dl, 11					; == '\r'
			je		increment
			cmp		dl, 32					; == ' '
			je		increment
			jmp		skip_sign
increment:
			inc		rcx
			jmp		skip_space
skip_sign:
			cmp		dl, 45
			je		minus
			mov		r11, 1					; r11 for sign
			cmp		dl, 43
			je		plus
			jmp		count
minus:
			mov		r11, -1
			inc		rcx
			jmp		count
plus:
			inc		rcx
count:
			mov		dl, [rdi + rcx]
			cmp		dl, 0
			je		finish
			xor		r8, r8
			jmp		search
continue:
			mul		r10
			add		rax, r8
			inc		rcx
			jmp		count
search:
			cmp		dl, [rsi + r8]
			je		continue
			inc		r8
			cmp		byte [rsi + r8], 0
			je		exit2
			jmp		search
finish:
			pop		rsi						; recover stack
			mul		r11						; in rax our sum
			ret
exit2:
			pop		rsi						; recover stack
			xor		rax, rax
			ret
exit:
			pop		rdi						; recover stack
			pop		rsi
			xor		rax, rax
			ret
