#include <stdio.h>
#include "stackHeader.h"

void push(void){
    double number;
    if(position == (STACK_LENGTH - 1)){
        (void) printf("Stack is full! \n");
        return;
    } else {
        (void) printf("Enter the element you want to push onto the stack, please. \n");
        (void) scanf("%lf", &number);
        position += 1;
        stack[position] = number;
    }
    return;
}

double pop(void){
    double number;
    if(position == -1){
        (void) printf("Stack is Empty\n");
        return (position);
    } else {
        number = stack[position];
        (void) printf("Poped element is = %.4lf \n", &number);
        position -= 1;
    }
    return (number);
}

void printStack(void){
    int i;
    if(position == -1){
        (void) printf("Stack is empty\n");
        return;
    } else {
        (void) printf("\n Your stack has a status of: \n");
        for( i = position; i >= 0; i--){
            (void) printf("%.4lf \n", stack[i]);
        }
    }
    (void) printf("\n");
}

void main (){
    int choice;
    int option = 1;
    position = -1;

    printf("STACK OPERATIONS AVAIBLE\n");
    while(option){
        (void) printf("---------------------------------\n");
        (void) printf("         1 ----->   PUSH         \n");
        (void) printf("         2 ----->   POP          \n");
        (void) printf("         3 ----->   PRINT STACK  \n");
        (void) printf("         4 ----->   QUIT!        \n");
        (void) printf("---------------------------------\n");

        (void) printf("Please enter your choice to proceed!\n");
        (void) scanf("%d", &choice);
        switch (choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printStack();
                break;
            case 4:
                return;
        }
        fflush(stdin);
        (void) printf("Would you like to continue? [0/1]?\n");
        (void) scanf("%d", &option);
    }
    (void) printf("Goodbye!");
}



