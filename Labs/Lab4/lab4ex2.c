#include <stdio.h>

//find out (add code to print) the address of the variable x in func1, and the variable y in func2.
//What did you observe? Can you explain this?

//both memory addresses and values are the same. Local variable x is created and destroyed when the function
//ends, and the same memory address is used to create y. The memory address is marked as open, but it must
//not have cleared the value stored there, so y still has value 7 since it's never initialized. 7 is garbage.

void func1(int xval){
    int x;
    x = xval;
    /* print the address and value of y here */
    printf("address: %p, value: %d\n", &x, x);
}

void func2(int dummy){
    int y;
    /* print the address and value of y here */
    printf("address: %p, value: %d\n", &y, y);
}

int main(void){
    func1(7);
    func2(11);

    return 0;
}