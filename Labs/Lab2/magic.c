#include <stdio.h>

int ismagic(int n, int A[n][n]){
    //initialize all arrays with 0's
    int rowsums[n];
    int colsums[n];
    for (int i = 0; i < n; i++) {
        rowsums[i] = 0;
        colsums[i] = 0;
    }
    int diagsums[2] = {0, 0};

    //these variables will be 1 if all rows are equal, 0 if not.
    int rowsEqual = 0, colsEqual = 0, diagsEqual = 0;

    //sum each row and check if theyre equal
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            rowsums[i] += A[i][j];
        }
    }

    for(int i = 0; i < n-2; i++){
        rowsEqual = (rowsums[i] == rowsums[i+1]);
        if((rowsEqual == 0)){
            return 0;
        }
    }

    //sum each column and check if theyre equal
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            colsums[i] += A[j][i];
        }
    }

    for(int i = 0; i < n-2; i++){
        colsEqual = (colsums[i] == colsums[i+1]);
        if(colsEqual == 0){
            return 0;
        }
    }

    //sum the diagonals and check if theyre equal
    for (int i = 0; i < n; i++){
        diagsums[0] += A[i][i];
    }
    int colIndex = n-1;
    for (int i = 0; i < n; i++){
        diagsums[1] += A[i][colIndex];
        colIndex--;
    }

    diagsEqual = (diagsums[0] == diagsums[1]);

    //Check if everything was equal
    if(rowsEqual == 1 && colsEqual == 1 && diagsEqual == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void){
    int n;

    printf("Enter the order of the magic square: \n");
    scanf("%d", &n);

    int A[n][n];

    printf("Enter the values of the magic square: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    int isMagic = ismagic(n, A);

    if(isMagic){
        printf("It's a magic square!");
    }
    else{
        printf("It's NOT a magic square :(");
    }

    return 0;
}