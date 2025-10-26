#include <stdio.h>
#include <math.h>

/**
 * returns 1 if arguments x and y can be added without causing overflow; 0 otherwise.
 * this version DEPENDENT ON WORDSIZE BEING PROVIDED.
 */
int uadd_ok_MY_FIRST_VERSION(unsigned x, unsigned y){
    //two unsigned integers can be added without causing overflow
    //in word size W if their sum is within the range of W   
    //for Unsigned, UMIN is always 0, UMAX is always ((2^W)-1)
    //Assume wordsize is 32.
    int W = 32;
    unsigned int UMAX = (unsigned) (pow(2,W)-1);
    //cant just add them and check if its greater than UMAX bc if they do overflow it wont work
    //how to check if a sum of 2 numbers will be greater than a certain threshold without actually summing them?
    //a + b <= c     rearrange --> a <= c - b      //x + y <= UMAX  --> x <= UMAX - y
    //EX 1000(8) + 0111(7) <= 1111(15) (TRUE) --> 1000(8) <= 1111(15) - 0111(7) (TRUE but we didnt have to sum)
    return (x <= UMAX - y);
}

/**
 * returns 1 if arguments x and y can be added without causing overflow; 0 otherwise.
 */
int uadd_ok(unsigned x, unsigned y){
    //if overflow occurs, the result will be smaller than both operands.
    //EX: 1111(15) + 0111(7) = 10110(22) but with overflow removed, it becomes 0110(6) smaller than both
    int sum = x + y;
    return (sum >= x);
}

/**
 * returns 1 if arguments x and y can be added without causing overflow; 0 otherwise.
 */
int tadd_ok(int x, int y){
    //Overflow only happens when two pos makes a neg
    //or two neg make a pos
    return !(x > 0 && y > 0 && x+y < 0) || (x < 0 && y < 0 && x+y > 0);

}

/**
 * PROFESSORS SOLUTION ^^
 */
int tadd_ok(int x, int y) 
{
   int sum = x + y;
   int neg_over = x < 0 && y < 0 && sum >= 0;
   int pos_over = x >= 0 && y >= 0 && sum < 0;
   return !neg_over && !pos_over;
}

/**
 * You are assigned the task of writing code for a function tsub_ok, with arguments x and y, that will
 * return 1 if computing x-y does not cause overflow. Based on the prior code, you write the following:
 */
int tsub_ok(int x, int y) {
    return tadd_ok(x, -y);
}
//For what values of x and y will this function give incorrect results?
//      Incorrect results when y=T_MIN bc the absolute value of T_MIN is always 1 more than the absolute
//      value of T_MAX, so overflow will occur

//Write a correct version of this function.
int tsub_ok(int x, int y) {
    int T_MIN = 0; //random holder number but u would calculate it or have it alr
    if (y == T_MIN){
        return 0;
    }
    return tadd_ok(x, -y);
}

/**
 * PROFESSORS SOLUTION ^^
 */
/* Determine whether arguments can be subtracted without overflow */
int tsub_ok(int x, int y) {
   int diff = x-y;
   int neg_over = x < 0 && y >= 0 && diff >= 0;
   int pos_over = x >= 0 && y < 0 && diff < 0;
   return !neg_over && !pos_over;
}


int main(void){
    return 0;
}