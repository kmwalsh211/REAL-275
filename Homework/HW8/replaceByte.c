#include <stdio.h>

void print_as_hex(unsigned i){
    printf("%#010X\n", i);
}

unsigned replace_byte (unsigned x, int i, unsigned b){
    int WORD_SIZE = 32;
    int MAX_BYTES = WORD_SIZE/8;
    unsigned og = x;
    
    printf("Original number: \n");
    print_as_hex(og);

    /** 
     * Clear the ith byte
     * 
     * ALGORITHM
     * STEP 1: shift right by i bytes - to get to rightmost position
     * STEP 2: shift left by MAX_BYTES-1 bytes (MAX_BYTES is wordsize/8) - to get to leftmost position
     * STEP 3: shift right by ((MAX_BYTES-1) - i) bytes - to get back to og position
     * STEP 4: subtract new x from og
     */
    x = x >> (i * 8);
    x = x << ((MAX_BYTES-1) * 8);
    x = x >> (((MAX_BYTES-1) - i) * 8);

    int CLEARED = og - x;
    printf("Ith byte cleared:\n");
    print_as_hex(CLEARED);

    /**
     * Insert b into ith byte
     * 
     * STEP 1: left shift b by i bytes
     * STEP 2: add to CLEARED
     */
    printf("b originally: \n");
    print_as_hex(b);

    b = b << (i * 8);

    printf("b:\n");
    print_as_hex(b);

    int ANSWER = CLEARED + b;

    //print answer
    printf("Final Answer: \n");
    print_as_hex(ANSWER);


    return 0;
}

int main(void){
    replace_byte(0x12345678, 0, 0xAB);
    return 0;
}

//------------CLEARING THE iTH BYTE-----------------------------------------------------

//i=1:   00000000 00110011 00100101 00001111 = 3,351,823
//.      00000000 00000000 00100101 00000000 = 9,472  
//.      00000000 00110011 00000000 00001111 = 3342351    = 3,351,823 - 9,472 

//OG: 00000000 00110011 *00100101* 00001111 --> want second byte (i=1)
//.   00000000 00000000 00110011 *00100101* - shifted right by 1 byte : STEP 1 clear right
//.   *00100101* 00000000 00000000 00000000 - shifted left by 3 bytes : STEP 2 clear left
//.   00000000 00000000 *00100101* 00000000 - shifted right by 2 bytes : STEP 3 shift back to place

//another ex -------
//OG: 01010101 01010101 01010101 *01010101* --> want first byte (i=0)
//.   *01010101* 00000000 00000000 00000000 - shifted left by 3 bytes : No right so STEP 2: clear left
//    00000000 00000000 00000000 01010101 - shifted right by 3 bytes : STEP 3 shift back to place

//another ex -------
//OG: 01010101 *01010101* 01010101 01010101 --> want third byte (i=2)
//.   00000000 00000000 01010101 *01010101* - shifted right 2 bytes : STEP 1 clear right
//.   *01010101* 00000000 00000000 00000000 - shifted left 3 bytes : STEP 2 clear left
//    00000000 *01010101* 00000000 00000000 - shifted right 1 byte : STEP 3 shift back to place

//ALGORITHM: 
//STEP 1: shift right by i - to get to rightmost position
//STEP 2: shift left by MAX_BYTES-1 (MAX_BYTES is wordsize/8) - to get to leftmost position
//STEP 3: shift right by ((MAX_BYTES-1) - i) - to get back to og position

//want to turn the byte to all 0's by shifting left and then right, then subtracting
//then add the number you want to add

//shift right by amount of bytes: its byte 1, so shift right by 1 byte

//------------INSERTING b INTO iTH BYTE-----------------------------------------------------
//