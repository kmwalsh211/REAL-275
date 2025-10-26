#include <stdio.h>

//returns the length of s, that is, the number of characters
//between the beginning of the string and the terminating null character.
int mystrlen(char *s){
    int count = 0;
    while(*s != '\0'){
        count++;
        s++;
    }

    return count;
}

//copies characters from src to dest strings and returns dest. Make sure dest is null-terminated.
char *mystrcpy(char *dest, char *src){
    char *startOfDest = dest; //save dests original starting pointer

    for(; *src != '\0'; src++){
        *dest = *src;
        dest++;
    }
    *dest = '\0';  

    return startOfDest;
}

//appends characters from src to the end of dest and returns dest. Make sure dest is null-terminated.
char *mystrcat(char *dest, char *src){
    char *startOfDest = dest; //save dests original starting pointer

    for(; *dest != '\0'; dest++){
        //do nothing. Were just incrementing dest to it's final value.
    }

    for(; *src != '\0'; src++){
        *dest = *src;
        dest++;
    }
    *dest = '\0';  

    return startOfDest;
}

int main(void){
    char *s1 = "Hello ";
    char *s2 = "CPSC 275!";
    char s3[20];

    printf("length of s1 = %d\n\n", mystrlen(s1));
    printf("s3 = %s\n\n", mystrcpy(s3, s1));
    printf("s3 = %s\n", mystrcat(s3, s2));

    return 0;
}