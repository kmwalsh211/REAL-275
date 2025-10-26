#include <stdio.h>

int main(void){
    //declare and initialize (to any value you like) a char, an int, a double, and a long.
    char a = 'K', *pa;
    int b = 1, *pb;
    double c = 2.0, *pc;
    long d = 3.0, *pd;

    //declare and initialize a pointer to each of the four variables.
    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;

    //print the address of each variable and the number of bytes each occupies in memory.
    printf("char: size = %zu, address = %p\n", sizeof(*pa), pa);
    printf("int: size = %zu, address = %p\n", sizeof(*pb), pb);
    printf("double: size = %zu, address = %p\n", sizeof(*pc), pc);
    printf("long: size = %zu, address = %p\n", sizeof(*pd), pd);
    
    return 0;
}