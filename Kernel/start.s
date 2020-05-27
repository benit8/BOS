.set MB_FLAG_ALIGN, 1 << 0
.set MB_FLAG_MMAP,  1 << 1
.set MB_MAGIC, 0x1BADB002
.set MB_FLAGS, MB_FLAG_ALIGN | MB_FLAG_MMAP
.set MB_CHECKSUM, (0 - (MB_MAGIC + MB_FLAGS))

.section .multiboot
.align 4
.long MB_MAGIC
.long MB_FLAGS
.long MB_CHECKSUM

.section .bss
.align 16
stack_bottom:
.skip 4096
stack_top:

.section .text
.global _start
_start:
	mov $stack_top, %esp
	call kernel_main
	cli
1:	hlt
	jmp 1b

.size _start, . - _start
