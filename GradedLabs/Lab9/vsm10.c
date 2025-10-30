/*
 * Program: vsm10.c 
 * Purpose: Runs VSM10 (Very Simple Machine 10) programs. Decodes and executes instructions of the 
 *          VSM10s 10-bit instruction set architecture.
 *          Program input must consist of 10-bit binary strings (the instructions) separated by a 
 *          space or new line, followed by necessary program inputs.
 * Author:  Kayla Walsh McCarter
 * Date:    10/30/2025
 */
#include <stdio.h>
#include <string.h>

/* Converts a 10-bit binary string to its decimal representation. */
unsigned short binstr2num (char *string);
/* Loads VSM instructions into memory. */
void loadMemory(unsigned short cMem[]);
/* Runs the program instructions until opcode HALT. */
void runProgram(unsigned short cMem[], unsigned short dMem[], short *accumulator, unsigned short *instRegister, unsigned short *programCounter, unsigned short *opcode, unsigned short *operand);
/* Decodes VSM10 instructions. */
void decode (unsigned short instr, unsigned short *opcode, unsigned short *opn);
/* Sign extends a 7 bit integer into 16 bits. */
short signExtend(unsigned short num);

int main(void){
    unsigned short cMem[64] = {0};         //128 byte code memory:  each index holds 16 bits/2 bytes/1 word
    unsigned short dMem[32] = {0};         //64 byte data memory:   each index holds 16 bits/2 bytes/1 word
    
    short accumulator = 0;                 //16-bit register
    unsigned short programCounter = 0;     //16 bit register stores address of next instr
    unsigned short instRegister = 0;       //10 bit register, MS 6 set to 0. holds current instr
    unsigned short opcode = 0;
    unsigned short operand = 0;
    
    loadMemory(cMem);
    runProgram(cMem, dMem, &accumulator, &instRegister, &programCounter, &opcode, &operand);
  
    return 0;
}

/*
 * Function: loadIntoMemory
 * Purpose:  Loads VSM instructions into memory
 *
 * Parameters:
 *    cMem: an array of type unsigned short
 */
void loadMemory(unsigned short cMem[]){
    char s[11];
    int x = 0;

    while(scanf("%10s", s) == 1){
        if (strcmp(s, "0000000000") == 0) { //HALT code has been reached
            break;
        }
        
        unsigned short sAsDec = binstr2num(s);
        cMem[x] = sAsDec;
        x++;
    }
}

/*
 * Function: binstr2num
 * Purpose:  Converts a 10-bit binary string into it's decimal representation.
 *
 * Parameters:
 *    string: a character pointer (the 10-bit binary string)
 *
 * Returns: the decimal value of the binary string as an unsigned short
 */
unsigned short binstr2num (char *string){
    unsigned short result = 0;
    int x = 0;
    for(int i = 9; i >= 0; i--){
        if(string[i] == '1'){
            result += (1 << x);
        }
        x++;
    }
    return result;
}

/*
 * Function: runProgram
 * Purpose:  Runs the program instructions until opcode HALT.
 *
 * Parameters:
 *    cMem: an array of type unsigned short
 *    dMem: an array of type unsigned short
 *    accumulator: a pointer to a short (the accumulator)
 *    instRegister: a pointer to an unsigned short (holds the current instruction)
 *    instCounter: a pointer to an unsigned short (holds the address of the next instruction)
 *    opcode: a pointer to an unsigned short (the operation code of the instruction)
 *    operand: a pointer to an unsigned short (the operand of the instruction)
 */
void runProgram(unsigned short cMem[], unsigned short dMem[], short *accumulator, unsigned short *instRegister, unsigned short *programCounter, unsigned short *opcode, unsigned short *operand){
    int running = 1;
    while(running){
        *instRegister = cMem[*programCounter];       //load next instr into current instr
        *programCounter += 1;                        //increment next instr
        decode(*instRegister, opcode, operand);      //loads the operand and opcode of the current instruction
        
        switch(*opcode){
            case 0:     //000 HALT
                running = 0;
                
            case 1:     //001 LOAD
                *accumulator = signExtend(*operand);
                break;
                
            case 2:     //010 MUL
                *accumulator *= signExtend(*operand);
                break;
                
            case 3:     //011 STORE
                dMem[*operand] = *accumulator;
                break;
            
            case 4:     //100 LOADM
                *accumulator = dMem[*operand];
                break;
                
            case 5:     //101 MULM
                *accumulator *= dMem[*operand];
                break;
                
            case 6:{    //110 READ
                short word;
                scanf("%hd", &word);
                dMem[*operand] = word;
                break;
            }
            case 7:     //111 WRITE
                printf("%hd\n", *accumulator);
                break;
        }
    }
}

/*
 * Function: decode
 * Purpose:  Decodes VSM instructions
 *
 * Parameters:
 *    instr: an unsigned short (the decimal form of the 10-bit binary instruction)
 *    opcode: a pointer to an unsigned short (will store the operation code of the instruction)
 *    opn: a pointer to an unsigned short (will store the operand of the instruction)
 *
 */
void decode (unsigned short instr, unsigned short *opcode, unsigned short *opn){
    *opcode = instr >> 7;
    *opn = instr & 0x007F;
}

/*
 * Function: signExtend
 * Purpose:  sign extends a 7 bit integer into 16 bits.
 *
 * Parameters:
 *    num: a pointer to a short
 *    
 * Returns:
 *    the short sign extended to 16 bits
 */
short signExtend(unsigned short num){
    if(num & 0x0020){   
        return (num | 0xFFC0);
    }
    else{
        return num;
    }
}
