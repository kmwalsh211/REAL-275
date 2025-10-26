# include <stdio.h>

float dotprod(float x[], float y[], int n){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += (x[i] * y[i]); 
    }
    return sum;
}

int main(void){
    int n;

    printf("Enter the size of the arrays: \n");
    scanf("%d", &n);

    float x[n];
    float y[n];

    printf("Enter %d integers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter %d integers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    printf("%.1f", dotprod(x, y, n));

    return 0;
}

