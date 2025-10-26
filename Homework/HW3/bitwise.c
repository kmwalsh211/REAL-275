# include <stdio.h>

void dec2bin(unsigned int x) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);   // shift down and isolate each bit
    }
    printf("\n");
}

void evenodd(int x){
    if(x & 1){
        printf("Odd\n");
    }
    else{
        printf("Even\n");
    }
}

void MSB(int x){
    int shifted = x >> 31;
    if(shifted & 1){
        printf("%d\n", 1);
    }
    else{
        printf("%d\n", 0);
    }
}

void nthBit(int x, int n){
    int shifted = x >> n;
    printf("%d\n", shifted & 1);
}

void setNth(int x, int n){
    int shifted = 1 << n;
    int newNum = x | shifted;
    printf("%d\n", newNum);
}

void clearNth(int x, int n){
    int shifted = ~(1 << n);
    int newNum = x & shifted;
    printf("%d\n", newNum);
}

void toggleNth(int x, int n){
    int shifted = (1 << n);
    int newNum = x ^ shifted;
    printf("%d\n", newNum);
}

void setBits(int x){
    int count = 0;
    for(int i = 0; i < 32; i++){
        if(x & 1){
            count++;
        }
        x = x >> 1;
    }
    printf("%d\n", count);
}

int main(void){

    //A - even or odd
    int A;
    printf("Enter a number to see if its even or odd: ");
    scanf("%d", &A);
    evenodd(A);

    //B - MSB
    int B;
    printf("Enter a number to find its MSB: ");
    scanf("%d", &B);
    MSB(B);

    //C - Nth bit from the right of X
    int Cx, Cn;
    printf("Enter a number to find its nth position: ");
    scanf("%d", &Cx);
    printf("Enter n: ");
    scanf("%d", &Cn);
    nthBit(Cx, Cn);

    //D - Set Nth
    int Dx, Dn;
    printf("Enter a number to set its nth position: ");
    scanf("%d", &Dx);
    printf("Enter n: ");
    scanf("%d", &Dn);
    printf("New number: \n");
    setNth(Dx, Dn);

    //D2 - Clear Nth
    int D2x, D2n;
    printf("Enter a number to clear its nth position: ");
    scanf("%d", &D2x);
    printf("Enter n: ");
    scanf("%d", &D2n);
    printf("New number: \n");
    clearNth(D2x, D2n);

    //D3 - Toggle Nth
    int D3x, D3n;
    printf("Enter a number to toggle its nth position: ");
    scanf("%d", &D3x);
    printf("Enter n: ");
    scanf("%d", &D3n);
    printf("New number: \n");
    toggleNth(D3x, D3n);

    //E - how many set (1) bits
    int E;
    printf("Enter a number to count its set bits: ");
    scanf("%d", &E);
    setBits(E);

    return 0;
}