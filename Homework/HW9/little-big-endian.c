#include <stdio.h>

void whichOne(){
	int test = 1; //stored as 4 bytes. On little endian, 
				  //theyre stored as [01] [00] [00] [00]
				  //on Big endian,   [00] [00] [00] [01]

	char *c = (char *) &test; //cast 4 byte address to 1 byte address, so its only the first byte

	if(*c){ //if the value of the first bite = 1, then its a little endian machine
		printf("I'm a little-endian machine");
	}
	else{ //if the first byte is 0, its big endian
		printf("I'm a big-endian machine");
	}
}


int main(void){
	whichOne();
	return 0;
}
