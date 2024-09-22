INCLUDE Irvine32.inc


.data
input1txt byte "Input first integer: ", 0
input2txt byte "Input second integer: ", 0
sumtxt byte "Total Sum: ",0

int1 DWORD ?
int2 DWORD ?
intsum DWORD ?

.code
main proc
call Clrscr
mov dl, 40
mov dh, 11
call Gotoxy
mov edx, OFFSET input1txt
call WriteString
call ReadInt
mov int1, eax

mov dl, 40
mov dh, 12
call Gotoxy
mov edx, OFFSET input2txt
call WriteString
call ReadInt
mov int2, eax;

mov eax, int2
add eax, int1
mov intsum, eax

mov dl, 40
mov dl, 13
call Gotoxy

mov edx, OFFSET sumtxt
call WriteString

mov eax, intsum
call WriteInt

exit

main endp
end main