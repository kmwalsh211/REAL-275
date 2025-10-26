/**
 * Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 − 1 (most significant).
 * Write a C function which will return an unsigned value in which
 * byte i of argument x has been replaced by byte b:
 * 
 * Here are some examples showing how the function should work:
 * 
 * replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
 * replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
 */


#include <stdio.h>

void print_as_hex(unsigned i){
    printf("%#010X\n", i);
}

unsigned replace_byte(unsigned x, int i, unsigned char b){
    //Create mask
    unsigned mask = 0xFF << (i * 8);
    //if i=1, it will be: 0000FF00
    
    //& with x to clear the ith byte
    unsigned cleared = x & ~mask;
    //if x=12345678, it will be: 12340078

    //shift b to ith byte
    unsigned shiftedB = (unsigned) b << (i * 8);

    //or with cleared
    unsigned answer = cleared | shiftedB;
    //12340078 | 0000FF00 = 1234FF78

    return answer;
}

int main(void){
    print_as_hex(replace_byte(0x12345678, 2, 0xAB));
    print_as_hex(replace_byte(0x12345678, 0, 0xAB));
    return 0;
}