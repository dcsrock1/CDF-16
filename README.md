# CDF-16
This repository is the full design, emulator, assembler, compiler and operating system for the CDF-16 system

## The fundamentals
This system is a 16 bit architecture. It is capable of most arithmetic tasks such as addition, subtraction, multiplication and division, it is also able to handle logical operations. This functionality is implemented by a 16 bit arithmetic logic unit. It has a 16 bit memory address bus, this allows it to access 64Kb of volatile memory, however this system makes use of a trick called memory bank switching, this system is implemented using a flag placed in the status register, that when set will redirect the address bus to the second memory bank. this allows to system to access a total of 128Kb of random access memory. The CDF-16 will also use the same memory switching method on dual NAND flash modules that will allow it to access 128Kb of non-volatile flash storage. This system will have dual 16 bit I/O lines that will allow the system to be partnered with addon cards such as a GPU, Storage Extension or basically anything you can imagine. Additionally it has 4 general purpose registers, A, B, C and D registers, A and B are 8 bit registers and C and D are 16 bit registers. It also contains a stack pointer (SP) and an accumulator (AC) and obviously contains a program counter (PC) along with a status register that was mentions earlier.

## Registers

### 8 Bit
* A Register: General purpose register
* B Register: General purpose register
* Status Register: Status flag register
### 16 bit register
* C Register: General purpose register
* D Register: General purpose register
* Accumulator: Arithmetic register used for mathematical operations
* Stack Pointer: Pointer to the end of the stack
* Program Counter: Tell the processor the next instruction to execute

