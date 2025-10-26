/* longline.c
 * Kayla Walsh McCarter
 */
 
#include <stdio.h>
#define MAXLINE 100  // maximum input size of a single line

int mygetline(char line[]);
void mycopy(char to[],char from[]);
    
/* iterate through lines of input
   keep track of longest line seen to so far
   print longest line 
*/
int main(void){
    int len;    		// current line length
    int max = 0;		// maximum length seen so far
    char line[MAXLINE];  //current input line
    char longest[MAXLINE]; // longest line is saved here

    while((len = mygetline(line)) != -1){
        if(len > max){
            max = len;
            mycopy(longest, line);
        }
    }

    printf("%s", longest);
    
    return 0;
}

/* getline: read a line into s, return length of line
   if EOF encountered, return -1
   (assumes last line has '\n')
   s should be a correctly formed string when complete ('\0')
*/
int mygetline(char line[]){
	int nChar = 0;
	int ch;

	while ((ch = getchar()) != EOF) {
		if (nChar < MAXLINE - 1) {  //leave space for '\0'
			line[nChar] = ch;
		}
		nChar++;

		if (ch == '\n') {  //end of this line
			break;
		}
	}

	if (ch == EOF && nChar == 0) {
		return -1; //true EOF as the return before pressing CTRL+D
	}
    if (ch == EOF && nChar != 0){
        printf("\nEntered input incorrectly. Make a new line before pretting Ctrl+D.");
        return -1;
    }

	// add null-terminator to end
	if (nChar < MAXLINE) {
		line[nChar] = '\0';
	} else {
		line[MAXLINE - 1] = '\0';
	}

	return nChar;
}

/* copy: copy  'from' into 'to' ;
   assumes 'from' is a correctly formed string 
*/
void mycopy(char to[], char from[]) {
    int i = 0;
    while(from[i] != '\n'){
        to[i] = from[i];
        i++;
    }
}