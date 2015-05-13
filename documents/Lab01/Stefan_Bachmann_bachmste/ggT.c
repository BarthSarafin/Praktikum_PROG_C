#include <stdio.h>
#include <stdlib.h>

int euklid(int dividend, int divisor);
int smallestSameMultiplier(int dividend, int divisor);
int scanner(void);
int choiceInput(void);

int euklid(int dividend, int divisor){

    if (dividend == 0){
        return divisor;
    }

    while(divisor != 0){
        if (dividend > divisor){
            dividend -= divisor;
        } else {
            divisor -= dividend;
        }
    }
    return dividend;
}

int smallestSameMultiplier(int dividend, int divisor){

    int sameDivisor = euklid(dividend, divisor);
    int smallestMultiplier = (dividend * divisor) / sameDivisor;

    return smallestMultiplier;
}

int scanner(void){

    int inputNumber;

    (void) printf("Please enter a number: \n");
    (void) scanf("%d",&inputNumber);

    return inputNumber;
}

int choiceInput(void) {

    unsigned char choice;

    (void) printf("\nWould you like to continue [Y/N]? \n");
    (void) scanf("%c",&choice);

    if(choice == 'y' || choice == 'Y'){
        return 1;
    } else if(choice == 'n' || choice == 'N'){
        return 0;
    } else {
        choiceInput();
    }
}

int main (void) {

    int dividend = 0;
    int divisor = 0;
    int choice = 1;

    while(choice == 1) {

        dividend = scanner();
        divisor = scanner();

        (void) printf("\nYou have entered %d and %d as the values of your variables. \n", dividend, divisor);
        (void) printf("ggT: %d \n", euklid(dividend, divisor));
        (void) printf("kgV: %d \n", smallestSameMultiplier(dividend, divisor));

        choice = choiceInput();
    }

    (void) printf("GoodBye!");
    return 0;
}