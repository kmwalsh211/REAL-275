/* temp.c
 * Kayla Walsh McCarter
 * CPSC 275
 */
#include <stdio.h>

int main(void) {
    int F;
    scanf("%d", &F);
    float C = (5.0/9.0) * (F - 32);
    printf("%d Fahrenheit is %.2f Celcius.\n", F, C);
    return 0;
}
