
main.o：     文件格式 elf64-x86-64
main.o
体系结构：i386:x86-64， 标志 0x00000011：
HAS_RELOC, HAS_SYMS
起始地址 0x0000000000000000

节：
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         0000002e  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000008  0000000000000000  0000000000000000  00000070  2**3
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000000  0000000000000000  0000000000000000  00000078  2**0
                  ALLOC
  3 .rodata.str1.1 00000004  0000000000000000  0000000000000000  00000078  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .comment      00000035  0000000000000000  0000000000000000  0000007c  2**0
                  CONTENTS, READONLY
  5 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000b1  2**0
                  CONTENTS, READONLY
  6 .eh_frame     00000030  0000000000000000  0000000000000000  000000b8  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 main.i
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .rodata.str1.1	0000000000000000 .rodata.str1.1
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	000000000000002e main
0000000000000000 g     O .data	0000000000000008 array
0000000000000000         *UND*	0000000000000000 sum
0000000000000000         *UND*	0000000000000000 printf



Disassembly of section .text:

0000000000000000 <main>:
   0:	48 83 ec 08          	sub    $0x8,%rsp
   4:	be 02 00 00 00       	mov    $0x2,%esi
   9:	bf 00 00 00 00       	mov    $0x0,%edi
			a: R_X86_64_32	array
   e:	e8 00 00 00 00       	callq  13 <main+0x13>
			f: R_X86_64_PC32	sum-0x4
  13:	89 c6                	mov    %eax,%esi
  15:	bf 00 00 00 00       	mov    $0x0,%edi
			16: R_X86_64_32	.rodata.str1.1
  1a:	b8 00 00 00 00       	mov    $0x0,%eax
  1f:	e8 00 00 00 00       	callq  24 <main+0x24>
			20: R_X86_64_PC32	printf-0x4
  24:	b8 00 00 00 00       	mov    $0x0,%eax
  29:	48 83 c4 08          	add    $0x8,%rsp
  2d:	c3                   	retq   
