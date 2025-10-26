/*
 * Program: assem.c 
 * Purpose: Decodes the machine code for the 16-bit instruction set architecture of the 
 *          VSM (Very Simple Machine) accumulator machine. The program takes 16-bit binary
 *          strings and interprets them as VSM instructions. It prints their hexadecimal value,
 *          the operation code of the instruction, and the operand of the instruction. 
 * Author:  Kayla Walsh McCarter
 * Date:    10/10/2025
 */
#include <stdio.h>

/* Converts a 16-bit binary string into it's decimal representation. */
unsigned short binstr2num (char *string);
/* Decodes VSM instructions. */
unsigned short decode (unsigned short instr, unsigned short *opcode, unsigned short *opn);

int main(void){
    char codes[16][6] = {"EOC  ", "LOAD ", "STORE", "READ ", "WRITE", "ADD  ", "SUB  ", "MUL  ",
                        "DIV  ", "MOD  ", "NEG  ", "NOP  ", "JUMP ", "JNEG ", "JZERO", "HALT "};
    
    unsigned short myopc = 0;
    unsigned short myopn = 0;

    char s[17];
    int ch;
    int i = 0;
    while((ch = getchar()) != EOF){ 
        if(ch == ' ' || ch == '\n'){
            s[i] = '\0';
            unsigned short dec = binstr2num(s);
            decode(dec, &myopc, &myopn);
            printf("%04X %s %04d\n", dec, codes[myopc], myopn);
            i = 0;
        }
        else{
            s[i] = ch;
            i++;
        }
    }
    
    return 0;
}

 /*
 * Function: binstr2num
 * Purpose:  Converts a 16-bit binary string into it's decimal representation.
 *
 * Parameters:
 *    string: a character pointer (the 16-bit binary string)
 *
 * Returns: the decimal value of the binary string as an unsigned short
 */
unsigned short binstr2num (char *string){
    unsigned short result = 0;
    int x = 0;
    for(int i = 15; i >= 0; i--){
        if(string[i] == '1'){
            result += (1 << x);
        }
        x++;
    }
    return result;
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
    *opn = instr & ~0xF800;
    int m = (instr >> 11) & 1;
    return m;
}