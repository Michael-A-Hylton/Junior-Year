INCLUDE Irvine32.inc


.data
colorstr byte "String to display in color",0

.code
main PROC

mov eax, blue
mov ecx,4
L1 :
	call SetTextColor
	mov edx, OFFSET colorstr
	call WriteString
	call Crlf
	add eax, 2
	loop L1

exit
main ENDP

END main