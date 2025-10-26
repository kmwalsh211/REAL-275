#include <stdio.h>
#include <string.h>

//convert strings to all uppercase letters
void printupper(char x[]){
    int length = strlen(x);
    for(int i = 0; i < length; i++){
        if((int) x[i] >= 97 && ((int) x[i] <= 122)){
            x[i] = x[i] - 32;
        }
    }
    printf("%s", x);
}

int main(void){
    char string[100] = "Hello World!";
    printupper(string);

    return 0;
}