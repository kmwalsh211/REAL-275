#include <stdio.h>

void func(int *, int);

void main()
{
   int x[] = {1, 2, 3, 4, 5};
   int y = 10000;

   func(x, y);
}

void func(int a[], int p){
   if(p > (sizeof(a) / sizeof(a[0]))){
      printf("Index out of bounds.\n");
      return;
   }
   printf("%d\n", a[p]);
}
