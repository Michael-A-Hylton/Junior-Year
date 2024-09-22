INCLUDE Irvine32.inc
.data
.code
main PROC
;Michael Hylton

;PartA

;The range of AL register goes from 0 to 255, so adding 1 to 255 sets the CF = 1
mov al, 255
add al, 1; adding to AL means AL = 0, CF = 1
call DumpRegs


sub al, 1; Subtracting from AL while it is unsignedand 0, it means AL = 255 and the CF is still set
call DumpRegs


sub al, 1; subtracting from 255 gives us AL = 254 and the carry flag is set to 0.
call DumpRegs

;Part B

; The range of ah register goes from - 128 to 127, so subtracting 1 from 1 sets the ZF
mov ah, 1
sub ah, 1; subtract 1 from AL means AL = 0, thus sets zero flag
call DumpRegs


sub ah, 1; subtract from AL while it is 0 sets signed flag and clears carry flag
call DumpRegs


add ah, 2; adding 2 clears both carry flag and zero flag since it is neither negative nor 0.
call DumpRegs

;Part C


mov bl, 127
add ah, bl; Since we add two positive registers and get a negative number, the overflow flag is set
call DumpRegs

add ah, 1; Adding 1 does to -128 produce overflow so overflow flag is cleared.
call DumpRegs

	exit
main ENDP
END main