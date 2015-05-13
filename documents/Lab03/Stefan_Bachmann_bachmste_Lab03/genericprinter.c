//
// Created by BarthSarafin on 24.03.2015.
//

#include "genericPrinter.h"
#include <stdio.h>

void print(void* source, int numElements, char type){
    int i = 0;
    switch(type){
        case CHAR: {
            for (i = 0; i < numElements; i++) {
                (void)printf("%c from %d Elements\n", *(char *) (source+i), numElements); // Alternative zu (char*)source)[i]
            }
            break;
        }
        case INT: {
            for (i = 0; i < numElements; i++) {
                (void)printf("%d from %d Elements\n",((int *)source)[i], numElements);
            }
            break;
        }
        case FLOAT: {
            for (i = 0; i < numElements; i++) {
                (void)printf("%.2f from %d Elements\n", ((float *) source)[i], numElements);
            }
            break;
        }
        case STRING: {
            (void)printf("%s with %d Elements\n", (char *) source, numElements);
            break;
        }
        default:
            (void)printf("Error. Please try again. The silence will fall.");
    }
}

void main (){

    char c[] = { 'X', 'M', 'A' };
    int d[] = { 54, 10, 11, 125, 12, 0 };
    float f[] = { 1.23, 2.34, 3.45, 4.56 };
    char s[] = {"In Transelore the silence will fall, when the eleventh comes to his end."};

    print((void *) c, sizeof(c) / sizeof(char), CHAR);
    print((void *) d, sizeof(d) / sizeof(int), INT);
    print((void *) f, sizeof(f) / sizeof(float), FLOAT);
    print((void *) s, sizeof(s) / sizeof(char), STRING);

}
