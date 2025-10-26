#include <stdio.h>

//given a numeric string as a parameter, returns an integer equivalent to the string.
//For example, str2num("2025") should return 2025.

//THIS IS TOTALLY AI GENERATED. I like vaguely understand it. 
int str2num(char str[]) {
    int result = 0;
    
    for(int i = 0; str[i] != '\0'; i++) {
        // Convert character to digit and add to result
        result = result * 10 + (str[i] - '0');
    }
    
    return result;
}

int main(void) {
    printf("%d\n", str2num("2025"));    // Output: 2025
    printf("%d\n", str2num("42"));      // Output: 42
    printf("%d\n", str2num("0"));       // Output: 0
    printf("%d\n", str2num("12345"));   // Output: 12345
    
    return 0;
}