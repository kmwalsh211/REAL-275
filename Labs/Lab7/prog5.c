#include <stdio.h>
#include <string.h>

char *strrev(char *, char *);

void main()
{
   char str[] = "hello";
   char out[20];

   printf("%s\n", strrev(out, str));
}

/* returns the reverse of src in dest */
char *strrev(char *dest, char *src) {
   char *p, *q;
   int len = strlen(src);
   int i;

   p = src + len - 1;
   q = dest;

   for (i = len; i > 0; i--) {
      *q++ = *p--;
   }
   return dest;   
}
