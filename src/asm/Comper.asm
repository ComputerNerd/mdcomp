; ---------------------------------------------------------------------------
; Original version written by vladikcomper, with improvements by Flamewing
; ---------------------------------------------------------------------------
; FUNCTION:
; 	CompDec
;
; DESCRIPTION
; 	Comper Decompressor
;
; INPUT:
; 	a0	Source address
; 	a1	Destination address
; ---------------------------------------------------------------------------
_Comp_LoopUnroll = 3

_Comp_RunBitStream macro
	dbra	d3,.mainloop	; if bits counter remains, parse the next word
	bra.ATTRIBUTE	.newblock		; start a new block
	endm

_Comp_ReadBit macro
	add.w	d0,d0			; roll description field
	endm
; ===========================================================================


; ||||||||||||||| S U B R O U T I N E |||||||||||||||||||||||||||||||||||||||
; ---------------------------------------------------------------------------
CompDec:
	moveq	#(1<<_Comp_LoopUnroll)-1,d7

.newblock:
	move.w	(a0)+,d0		; fetch description field
	moveq	#15,d3			; set bits counter to 16

.mainloop:
	_Comp_ReadBit
	bcs.s	.flag			; if a flag issued, branch
	move.w	(a0)+,(a1)+		; otherwise, do uncompressed data
	_Comp_RunBitStream.s
; ---------------------------------------------------------------------------
.flag:
	moveq	#-1,d1			; init displacement
	move.b	(a0)+,d1		; load displacement
	add.w	d1,d1
	moveq	#0,d2			; init copy count
	move.b	(a0)+,d2		; load copy length
	beq.s	.end			; if zero, branch
	lea	(a1,d1.w),a2		; load start copy address
	move.w	d2,d4
	not.w	d4
	and.w	d7,d4
	add.w	d4,d4
	lsr.w	#_Comp_LoopUnroll,d2
	jmp	.loop(pc,d4.w)
; ---------------------------------------------------------------------------
.loop:
	rept (1<<_Comp_LoopUnroll)
		move.w	(a2)+,(a1)+		; copy given sequence
	endm
	dbra	d2,.loop		; repeat
	_Comp_RunBitStream.s
; ---------------------------------------------------------------------------
.end:
	rts
; ===========================================================================
