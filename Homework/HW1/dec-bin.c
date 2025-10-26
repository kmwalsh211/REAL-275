/* dec-bin.c
 * Kayla Walsh McCarter
 * CPSC 275
 */
#include <stdio.h>

void dec2bin(int n) {
    int binform[32];
    int index = 0;

    while(n > 0){
        binform[index] = n%2;
        n = n/2;
        index++;
    }

    for(int i = index-1; i >= 0; i--){
        printf("%d", binform[i]);
    }
}

int main(void) {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    dec2bin(n);
    return 0;
}