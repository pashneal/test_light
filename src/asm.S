/* PRU clock rate */
#define CPU_HZ	(200 * 1000 * 1000)

	.text
	.section .init0, "x"
	.global	_start
_start:
	/* Initialize stack pointer. */
	ldi32	sp, _stack_top
	jmp	main

	.text
	.section .text
main:
	ldi	r0, 0
	ldi	r1, 0xffff

main_loop:
	ldi32	r14, CPU_HZ / 4
	call	delay_n2_cycles
	/* DING */
	mov	r30, r0
	ldi32	r14, CPU_HZ / 4
	call	delay_n2_cycles
	/* DONG */
	mov	r30, r1
	jmp main_loop

delay_n2_cycles:
	sub	r14, r14, 1
	qbne	delay_n2_cycles, r14, 0
	ret
