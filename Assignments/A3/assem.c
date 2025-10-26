/*
 * Program: assem.c 
 * Purpose: Runs VSM (Very Simple Machine) programs. Decodes and executes instructions of the 
 *          VSMs 16-bit instruction set architecture, and then prints a computer dump showing the
 *          state of the VSMs memory and registers at the end of program execution.
 *          Program input must consist of 16-bit binary strings (the instructions) separated by a 
 *          space or new line, followed by necessary program inputs.
 * Author:  Kayla Walsh McCarter
 * Date:    10/10/2025
 */
#include <stdio.h>
#include <string.h>

/* Loads VSM instructions into memory. */
void loadIntoMemory(unsigned char memory[]);
/* Runs the program instructions until opcode HALT or EOC. */
void runProgram(unsigned char memory[], short *accumulator, unsigned short *instRegister, unsigned short *instCounter, unsigned short *opcode, unsigned short *operand);
/* Decodes VSM instructions. */
unsigned short decode (unsigned short instr, unsigned short *opcode, unsigned short *opn);
/* Sign extends an 11 bit integer into 16 bits. */
short signExtend(unsigned short num);
/* Prints the contents of the VSMs registers and memory at end of program execution. */
void computerDump(unsigned char memory[], short *accumulator, unsigned short *instRegister, unsigned short *instCounter, unsigned short *opcode, unsigned short *operand);

int main(void){
    unsigned char memory[2048] = {0};

    loadIntoMemory(memory);

    short accumulator = 0;
    unsigned short instCounter = 0;
    unsigned short instRegister = 0;
    unsigned short opcode = 0;
    unsigned short operand = 0;

    runProgram(memory, &accumulator, &instRegister, &instCounter, &opcode, &operand);
    computerDump(memory, &accumulator, &instRegister, &instCounter, &opcode, &operand);

    return 0;
}

/*
 * Function: loadIntoMemory
 * Purpose:  Loads VSM instructions into memory
 *
 * Parameters:
 *    memory: an array of type unsigned char
 */
void loadIntoMemory(unsigned char memory[]){
    char s[17];
    int x = 0;

    while(scanf("%16s", s) == 1){
        if (strcmp(s, "0000000000000000") == 0) {
            break;
        }
        
        unsigned char highByte = 0;
        for(int i = 0; i < 8; i++){
            highByte = (highByte << 1) | (s[i] - '0');
        }
        memory[x] = highByte;

        unsigned char lowByte = 0;
        for(int i = 8; i < 16; i++){
            lowByte = (lowByte << 1) | (s[i] - '0');
        }
        memory[x+1] = lowByte;

        x += 2;
    }
}

/*
 * Function: runProgram
 * Purpose:  Runs the program instructions until opcode HALT.
 *
 * Parameters:
 *    memory: an array of type unsigned char
 *    accumulator: a pointer to a short (the accumulator)
 *    instRegister: a pointer to an unsigned short (holds the current instruction)
 *    instCounter: a pointer to an unsigned short (holds the address of the next instruction)
 *    opcode: a pointer to an unsigned short (the operation code of the instruction)
 *    operand: a pointer to an unsigned short (the operand of the instruction)
 */
void runProgram(unsigned char memory[], short *accumulator, unsigned short *instRegister, unsigned short *instCounter, unsigned short *opcode, unsigned short *operand){
    int running = 1;
    while(running){
        *instRegister = (memory[*instCounter] << 8) | memory[*instCounter + 1];
        *instCounter += 2;
        int m = decode(*instRegister, opcode, operand);

        switch(*opcode){
            case 1: //0001 LOAD a word at a specific location in memory (or a number) into the accumulator.
                if(m == 1){
                    *accumulator = signExtend(*operand);
                }
                else{
                    *accumulator = (memory[*operand] << 8) | (memory[*operand + 1]);
                }
                break;

            case 2: //0010 STORE a word in the accumulator into a specific location in memory.
                memory[*operand] = *accumulator >> 8;
                memory[*operand + 1] = *accumulator & 0xFF;
                break;

            case 3:{ //0011 READ a word from the standard input into a specific location in memory.
                short word;
                scanf("%hd", &word);
                memory[*operand] = word >> 8;
                memory[*operand + 1] = word & 0xFF;
                break;
            }
            case 4:{ //0100 WRITE a word at a specific location in memory to the standard output.
                short value = (memory[*operand] << 8) | memory[*operand + 1];
                printf("%hd\n", value);
                break;
            }
            case 5: //0101 ADD a word at a specific location in memory (or a number) to the word 
                    //in the accumulator, leaving the sum in the accumulator.
                if(m == 1){
                    *accumulator += signExtend(*operand);
                }
                else{
                    *accumulator += ((memory[*operand] << 8) | memory[*operand + 1]);
                }
                break;

            case 6: //0110 Subtract a word at a specific location in memory (or a number) from the
                    //word in the accumulator, leaving the difference in the accumulator.
                if(m == 1){
                    *accumulator -= signExtend(*operand);
                }
                else{
                    *accumulator -= ((memory[*operand] << 8) | memory[*operand + 1]);
                }
                break;

            case 7: //0111 MULTIPLY the word in the accumulator by a word at a specific location in
                    //memory (or a number), leaving the product in the accumulator.
                if(m == 1){
                    *accumulator *= signExtend(*operand);
                }
                else{
                    *accumulator *= ((memory[*operand] << 8) | (memory[*operand + 1]));
                }
                break;

            case 8: //1000 DIVIDE the word in the accumulator by a word at a specific location in
                    //memory (or a number), leaving the quotient in the accumulator.
                if(m == 1){
                    *accumulator /= signExtend(*operand);
                }
                else{
                    *accumulator /= ((memory[*operand] << 8) | (memory[*operand + 1]));
                }
                break;

            case 9: //1001 MOD Divide the word in the accumulator by a word at a specific location
                    //in memory (or a number), leaving the remainder in the accumulator.
                if(m == 1){
                    *accumulator %= signExtend(*operand);
                }
                else{
                    *accumulator %= ((memory[*operand] << 8) | (memory[*operand + 1]));
                }
                break;

            case 10: //1010 NEGATE the word in the accumulator.
                *accumulator = -(*accumulator);
                break;

            case 11: //1011 NOP no operation.
                break;

            case 12: //1100 JUMP branch to a specific location in memory.
                *instCounter = (*operand);
                break;

            case 13: //1101 JNEG branch to a specific location in memory if the accumulator is negative.
                if(*accumulator < 0){
                    *instCounter = (*operand);
                }
                break;
            
            case 14: //1110 JZERO branch to a specific location in memory if the accumulator is zero.
                if(*accumulator == 0){
                    *instCounter = (*operand);
                }
                break;
            
            case 15: //1111 HALT stop the program.
                running = 0;
        }
    }
}

/*
 * Function: decode
 * Purpose:  Decodes VSM instructions
 *
 * Parameters:
 *    instr: an unsigned short (the decimal form of the 16-bit binary instruction)
 *    opcode: a pointer to an unsigned short (will store the operation code of the instruction)
 *    opn: a pointer to an unsigned short (will store the operand of the instruction)
 *
 * Returns:
 *    m: an integer, either 0 or 1. m is the 5th bit of the instruction and determines
 *       the nature of the operand. 0 indicates the operand is a memory address. 1
 *       indicates the operand is an integer.
 */
unsigned short decode (unsigned short instr, unsigned short *opcode, unsigned short *opn){
    *opcode = instr >> 12;
    *opn = instr & 0x7FF;
    int m = (instr >> 11) & 1;
    return m;
}

/*
 * Function: signExtend
 * Purpose:  sign extends an 11 bit integer into 16 bits.
 *
 * Parameters:
 *    num: a pointer to a short
 *    
 * Returns:
 *    the short sign extended to 16 bits
 */
short signExtend(unsigned short num){
    if(num & 0x0400){
        return (num | 0xF800); 
    }
    else{
        return num;
    }
}

/*
 * Function: computerDump
 * Purpose:  prints the contents of the VSMs registers and memory. It shows the actual
 *           instruction and data values at the point execution of a program terminates.
 *
 * Parameters:
 *    memory: an array of type unsigned char
 *    accumulator: a pointer to a short (the accumulator)
 *    instRegister: a pointer to an unsigned short (holds the current instruction)
 *    instCounter: a pointer to an unsigned short (holds the address of the next instruction)
 *    opcode: a pointer to an unsigned short (the operation code of the instruction)
 *    operand: a pointer to an unsigned short (the operand of the instruction)
 */
void computerDump(unsigned char memory[], short *accumulator, unsigned short *instRegister, unsigned short *instCounter, unsigned short *opcode, unsigned short *operand){
    printf("\nREGISTERS:\n");
    printf("%-30s 0x%04X\n", "accumulator", *accumulator);
    printf("%-30s 0x%04X\n", "instructionCounter", *instCounter);
    printf("%-30s 0x%04X\n", "instructionRegister", *instRegister);
    printf("%-30s 0x%X\n", "opCode", *opcode);
    printf("%-30s 0x%04X\n", "operand", *operand);

    printf("\nCODE:\n");
    printf("     ");
    for (int i = 0; i < 10; i++) {
        printf("%d  ", i);
    }
    for(int y = 0; y < 10; y++){
        printf("\n%04d ", y*10);
        for(int i = 0; i < 10; i++){
            printf("%02X ", memory[i+(y*10)]);
        }
    }
    printf("\n...\n");

    printf("\nDATA:\n");
    printf("     ");
    for (int i = 0; i < 10; i++) {
        printf("%d  ", i);
    }
    for(int y = 0; y < 10; y++){
        printf("\n%04d ", (y*10)+1024);
        for(int i = 0; i < 10; i++){
            printf("%02X ", memory[i+(y*10)+1024]);
        }
    }
    printf("\n...\n");
}