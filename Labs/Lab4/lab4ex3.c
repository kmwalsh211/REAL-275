#include <stdio.h>

int main(void){
    //CHARACTER - 1 byte long
    char c = 'Z';
    char *cp = &c;

    printf("cp is %p\n", cp);
    printf("The character at cp is %c\n", *cp);

    /* Pointer arithmetic - see what cp+1 is */
    cp = cp + 1;
    printf("cp is now %p\n\n\n", cp);

    /* Note: Do not try to print *cp here, because it points to the
        memory location unallocated to your program */

    //INTEGER - 4 bytes long
    int i = 7;
    int *ci = &i;

    printf("ci is %p\n", ci);
    printf("The integer at ci is %d\n", *ci);

    ci = ci + 1;
    printf("ci is now %p\n\n\n", ci);

    //DOUBLE - 8 bytes long
    double d = 7.0;
    double *cd = &d;

    printf("cd is %p\n", cd);
    printf("The integer at cd is %f\n", *cd);

    cd = cd + 1;
    printf("cd is now %p\n\n\n", cd);

    //adding 2 instead of one will add 2 to the char mem address,
    //8 to the int mem address, and 16 to the double mem address.

    return 0;
}
