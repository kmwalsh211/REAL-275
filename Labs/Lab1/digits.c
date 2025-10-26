/* digits.c
 * Kayla Walsh McCarter
 * CPSC 275
 */
 #include <stdio.h>
 #include <string.h>

 int main(void) {
    //digits are input as a string (character array)
    char digits[50];
    scanf("%s", &digits);
    //length of the string (number of digits) is determined
    int length = strlen(digits);

    //for loop prints each digit
    for (int i=0; i < length; i++){
        printf("%c", digits[i]);
        //prints an asterik between each digit except for the final digit
        if (i != length-1){
            printf("*");
        }
    }

    return 0;
 }