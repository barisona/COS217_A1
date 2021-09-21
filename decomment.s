	.cpu generic+fp+simd
	.file	"decomment.c"
	.text
	.align	2
	.global	handleNormalState
	.type	handleNormalState, %function
handleNormalState:
.LFB0:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	str	w0, [x29,28]
	ldr	w0, [x29,28]
	cmp	w0, 39
	bne	.L2
	ldr	w0, [x29,28]
	bl	putchar
	mov	w0, 5
	str	w0, [x29,44]
	b	.L3
.L2:
	ldr	w0, [x29,28]
	cmp	w0, 34
	bne	.L4
	ldr	w0, [x29,28]
	bl	putchar
	mov	w0, 4
	str	w0, [x29,44]
	b	.L3
.L4:
	ldr	w0, [x29,28]
	cmp	w0, 47
	bne	.L5
	mov	w0, 1
	str	w0, [x29,44]
	b	.L3
.L5:
	ldr	w0, [x29,28]
	bl	putchar
	str	wzr, [x29,44]
.L3:
	ldr	w0, [x29,44]
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE0:
	.size	handleNormalState, .-handleNormalState
	.align	2
	.global	handleStartSlashState
	.type	handleStartSlashState, %function
handleStartSlashState:
.LFB1:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	str	w0, [x29,28]
	ldr	w0, [x29,28]
	cmp	w0, 42
	bne	.L8
	mov	w0, 32
	bl	putchar
	mov	w0, 2
	str	w0, [x29,44]
	b	.L9
.L8:
	ldr	w0, [x29,28]
	cmp	w0, 39
	bne	.L10
	mov	w0, 47
	bl	putchar
	ldr	w0, [x29,28]
	bl	putchar
	mov	w0, 5
	str	w0, [x29,44]
	b	.L9
.L10:
	ldr	w0, [x29,28]
	cmp	w0, 34
	bne	.L11
	mov	w0, 47
	bl	putchar
	ldr	w0, [x29,28]
	bl	putchar
	mov	w0, 4
	str	w0, [x29,44]
	b	.L9
.L11:
	ldr	w0, [x29,28]
	cmp	w0, 47
	bne	.L12
	mov	w0, 47
	bl	putchar
	mov	w0, 1
	str	w0, [x29,44]
	b	.L9
.L12:
	mov	w0, 47
	bl	putchar
	ldr	w0, [x29,28]
	bl	putchar
	str	wzr, [x29,44]
.L9:
	ldr	w0, [x29,44]
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE1:
	.size	handleStartSlashState, .-handleStartSlashState
	.align	2
	.global	handleCommentState
	.type	handleCommentState, %function
handleCommentState:
.LFB2:
	.cfi_startproc
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	w0, [sp,12]
	ldr	w0, [sp,12]
	cmp	w0, 42
	bne	.L15
	mov	w0, 3
	str	w0, [sp,28]
	b	.L16
.L15:
	mov	w0, 2
	str	w0, [sp,28]
.L16:
	ldr	w0, [sp,28]
	add	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2:
	.size	handleCommentState, .-handleCommentState
	.align	2
	.global	handleEndStarState
	.type	handleEndStarState, %function
handleEndStarState:
.LFB3:
	.cfi_startproc
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	w0, [sp,12]
	ldr	w0, [sp,12]
	cmp	w0, 47
	bne	.L19
	str	wzr, [sp,28]
	b	.L20
.L19:
	ldr	w0, [sp,12]
	cmp	w0, 42
	bne	.L21
	mov	w0, 3
	str	w0, [sp,28]
	b	.L20
.L21:
	mov	w0, 2
	str	w0, [sp,28]
.L20:
	ldr	w0, [sp,28]
	add	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE3:
	.size	handleEndStarState, .-handleEndStarState
	.align	2
	.global	handleCharLiteralState
	.type	handleCharLiteralState, %function
handleCharLiteralState:
.LFB4:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	str	w0, [x29,28]
	ldr	w0, [x29,28]
	cmp	w0, 92
	bne	.L24
	ldr	w0, [x29,28]
	bl	putchar
	mov	w0, 7
	str	w0, [x29,44]
	b	.L25
.L24:
	ldr	w0, [x29,28]
	cmp	w0, 39
	bne	.L26
	ldr	w0, [x29,28]
	bl	putchar
	str	wzr, [x29,44]
	b	.L25
.L26:
	ldr	w0, [x29,28]
	bl	putchar
	mov	w0, 5
	str	w0, [x29,44]
.L25:
	ldr	w0, [x29,44]
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE4:
	.size	handleCharLiteralState, .-handleCharLiteralState
	.align	2
	.global	handleStrLiteralState
	.type	handleStrLiteralState, %function
handleStrLiteralState:
.LFB5:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	str	w0, [x29,28]
	ldr	w0, [x29,28]
	cmp	w0, 92
	bne	.L29
	ldr	w0, [x29,28]
	bl	putchar
	mov	w0, 6
	str	w0, [x29,44]
	b	.L30
.L29:
	ldr	w0, [x29,28]
	cmp	w0, 34
	bne	.L31
	ldr	w0, [x29,28]
	bl	putchar
	str	wzr, [x29,44]
	b	.L30
.L31:
	ldr	w0, [x29,28]
	bl	putchar
	mov	w0, 4
	str	w0, [x29,44]
.L30:
	ldr	w0, [x29,44]
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE5:
	.size	handleStrLiteralState, .-handleStrLiteralState
	.align	2
	.global	handleCharEscapeState
	.type	handleCharEscapeState, %function
handleCharEscapeState:
.LFB6:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	str	w0, [x29,28]
	ldr	w0, [x29,28]
	bl	putchar
	mov	w0, 5
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE6:
	.size	handleCharEscapeState, .-handleCharEscapeState
	.align	2
	.global	handleStrEscapeState
	.type	handleStrEscapeState, %function
handleStrEscapeState:
.LFB7:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	str	w0, [x29,28]
	ldr	w0, [x29,28]
	bl	putchar
	mov	w0, 4
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE7:
	.size	handleStrEscapeState, .-handleStrEscapeState
	.section	.rodata
	.align	3
.LC0:
	.string	"Error: line %d: unterminated comment\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB8:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	str	wzr, [x29,28]
	mov	w0, 1
	str	w0, [x29,24]
	str	wzr, [x29,20]
	b	.L38
.L52:
	ldr	w0, [x29,16]
	cmp	w0, 10
	bne	.L39
	ldr	w0, [x29,28]
	cmp	w0, 2
	beq	.L40
	ldr	w0, [x29,28]
	cmp	w0, 3
	bne	.L41
.L40:
	ldr	w0, [x29,20]
	add	w0, w0, 1
	str	w0, [x29,20]
	ldr	w0, [x29,16]
	bl	putchar
	b	.L42
.L41:
	str	wzr, [x29,20]
.L42:
	ldr	w0, [x29,24]
	add	w0, w0, 1
	str	w0, [x29,24]
.L39:
	ldr	w0, [x29,28]
	cmp	w0, 7
	bhi	.L38
	adrp	x1, .L44
	add	x1, x1, :lo12:.L44
	ldr	w2, [x1,w0,uxtw #2]
	adr	x3, .Lrtx44
	add	x2, x3, w2, sxtw #2
	br	x2
.Lrtx44:
	.section	.rodata
	.align	0
	.align	2
.L44:
	.word	(.L43 - .Lrtx44) / 4
	.word	(.L45 - .Lrtx44) / 4
	.word	(.L46 - .Lrtx44) / 4
	.word	(.L47 - .Lrtx44) / 4
	.word	(.L48 - .Lrtx44) / 4
	.word	(.L49 - .Lrtx44) / 4
	.word	(.L50 - .Lrtx44) / 4
	.word	(.L51 - .Lrtx44) / 4
	.text
.L43:
	ldr	w0, [x29,16]
	bl	handleNormalState
	str	w0, [x29,28]
	b	.L38
.L45:
	ldr	w0, [x29,16]
	bl	handleStartSlashState
	str	w0, [x29,28]
	b	.L38
.L46:
	ldr	w0, [x29,16]
	bl	handleCommentState
	str	w0, [x29,28]
	b	.L38
.L47:
	ldr	w0, [x29,16]
	bl	handleEndStarState
	str	w0, [x29,28]
	b	.L38
.L49:
	ldr	w0, [x29,16]
	bl	handleCharLiteralState
	str	w0, [x29,28]
	b	.L38
.L48:
	ldr	w0, [x29,16]
	bl	handleStrLiteralState
	str	w0, [x29,28]
	b	.L38
.L51:
	ldr	w0, [x29,16]
	bl	handleCharEscapeState
	str	w0, [x29,28]
	b	.L38
.L50:
	ldr	w0, [x29,16]
	bl	handleStrEscapeState
	str	w0, [x29,28]
	nop
.L38:
	bl	getchar
	str	w0, [x29,16]
	ldr	w0, [x29,16]
	cmn	w0, #1
	bne	.L52
	ldr	w0, [x29,28]
	cmp	w0, 1
	bne	.L53
	mov	w0, 47
	bl	putchar
.L53:
	ldr	w0, [x29,28]
	cmp	w0, 2
	beq	.L54
	ldr	w0, [x29,28]
	cmp	w0, 3
	bne	.L55
.L54:
	adrp	x0, stderr
	add	x0, x0, :lo12:stderr
	ldr	x0, [x0]
	ldr	w2, [x29,24]
	ldr	w1, [x29,20]
	sub	w2, w2, w1
	adrp	x1, .LC0
	add	x1, x1, :lo12:.LC0
	bl	fprintf
	mov	w0, 1
	b	.L56
.L55:
	mov	w0, 0
.L56:
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-28)"
	.section	.note.GNU-stack,"",%progbits
