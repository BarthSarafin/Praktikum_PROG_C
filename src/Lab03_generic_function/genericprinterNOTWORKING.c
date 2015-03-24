//
// Created by BarthSarafin on 23.03.2015.
//

#include "genericprinterNOTWORKING.h"
#include <stdio.h>

void genPrint(void * source, int numElements, char size, void (*printFunction)(void *)){
    int i;
    for (i = 0; i < numElements; i++){
        printFunction(((char *)source) + i * size);
    }
}

int printStruct(struct RECORD *r){
    switch(r->t){
        case CHAR:
            return printf("%c", *((char*)(r->source)));
        case INT:
            return printf("%d", *((int*)r->source));
        case FLOAT:
            return printf("%.6f", *((float*)r->source));
        case STRING:
            return printf("%s", (char*)r->source);
        default:
            return printf("Error. Please try again. The silence will fall.");
    }
}

void print(void* source, int numElements, char type){
    int i = 0;
    switch(type){
        case CHAR: {
            for (i = 0; i < numElements; i++) {
                printf("%c from %d Elements\n", *(char *) (source+i), numElements); // Alternative zu (char*)source)[i]
            }
            break;
        }
        case INT: {

            for (i = 0; i < numElements; i++) {
                printf("%d from %d Elements\n",((int *)source)[i], numElements);
            }
            break;
        }
        case FLOAT: {
            for (i = 0; i < numElements; i++) {
                printf("%.2f and %d Elements\n", ((float *) source)[i], numElements);
            }
            break;
        }
        case STRING: {
            for (i = 0; i < numElements; i++) {
                printf("%s and %d Elements\n", (char *) source, numElements);
            }
            break;
        }
        default:
            printf("Error. Please try again. The silence will fall.");
    }
}

void main (){

    char c[] = { 'X', 'M', 'A' };
    int d[] = { 54, 10, 11, 125, 12, 0 };
    float f[] = { 1.23, 2.34, 3.45, 4.56 };

   RECORD cha = { c, sizeof(c) / sizeof(char), CHAR };

    printStruct(cha);

    print((void *) c, sizeof(c) / sizeof(char), CHAR);
    print((void *) d, sizeof(d) / sizeof(int), INT);
    print((void *) f, sizeof(f) / sizeof(float), FLOAT);

    genPrint((void *) c, sizeof(c) / sizeof(char), 'c', printFunction);
    genPrint((void *) d, sizeof(d) / sizeof(int), 'd', printFunction);
    genPrint((void *) f, sizeof(f) / sizeof(float), 'f', printFunction);



}
