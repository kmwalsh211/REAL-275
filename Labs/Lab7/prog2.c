#include <stdio.h>

void func(int, int);

void main()
{
   int x, y;

   x = 5;
   y = 2;
   func(x, y);

   y = x - y;
   x = 3;
   func(x, y);
}

void func(int a, int b){
   if(a - b == 0){
	printf("Cannot divide by 0.\n");
	return;
   }
   printf("%d\n", a / (a - b));
}
