//
// Created by BarthSarafin on 23.03.2015.
//

#include "genericprinter.h"
#include <stdio.h>

void genPrint(void * source, int numElements, char size, void (*printFunction)(void *)){
    int i;
    for (i = 0; i < numElements; i++){
        printFunction(((char *)source) + i * size);
    }
}

void main (){

    char c[] = { 'X', 'M', 'A' };
    int d[] = { 54, 10, 11, 125, 12, 0 };
    float f[] = { 1.23, 2.34, 3.45, 4.56 };

    genPrint((void *) c, sizeof(c) / sizeof(char), 'c');
    genPrint((void *) d, sizeof(d) / sizeof(int), 'd');
    genPrint((void *) f, sizeof(f) / sizeof(float), 'f');

}
