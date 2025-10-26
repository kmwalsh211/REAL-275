void func(int *, int);

void main()
{
   int x = 0;
   func(&x, 5);

   int p = 0;
   int *y = &p;
   func(y, 10);
}

void func(int *a, int p){
   *a = p;
}
