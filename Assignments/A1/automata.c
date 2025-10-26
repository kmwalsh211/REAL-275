#include <stdio.h>
#include <string.h>
#include <math.h>

void cellular_automata(char s[], int rule, int n){
    int sLength = strlen(s);
    char thisGen[sLength];
    strcpy(thisGen, s);
    int active[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    //Map array 'active' to binary representation of rule
    for(int i=0; i<8; i++){
        active[i] = (rule >> i) & 1;
    }

    //for each generation
    for(int gen=0; gen<n; gen++){
        char nextGen[sLength];
        //for each position k in thisGen
        for(int k=0; k<sLength; k++){
            //calculate integer value represented by k and it's neighbors
            //treat circularly by adding sLength and then modulo sLength
            //must subtract '0' because char is stored as ASCII code 0=48, 1=49
            int neighborhood = (thisGen[(k-1+sLength)%sLength] - '0') * pow(2,2) +
                               (thisGen[k] - '0') * pow(2,1) +
                               (thisGen[(k+1+sLength)%sLength] - '0') * pow(2,0);
            //for each of the 8 patterns
            for(int pattern=0; pattern<8; pattern++){
                if(neighborhood == pattern){
                    //position k now becomes the value stored in 'active' for it's pattern
                    //must add '0' because 'active' is an int array and 'newString' is a char array
                    nextGen[k] = active[pattern] + '0';
                    break; //neighborhood can only match 1 of the 8 patterns
                } 
            }
        }
        strcpy(thisGen, nextGen);
    }
    printf("%s\n", thisGen);
}


int main(void){
    int m; //number of test cases
    scanf("%d", &m);

    char initialString[50];
    int rule;
    int generations;

    for(int i=0; i<m; i++){
        scanf("%s %d %d", initialString, &rule, &generations);
        cellular_automata(initialString, rule, generations);
    }
    
    return 0;
}