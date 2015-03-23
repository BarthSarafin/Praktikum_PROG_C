//
// Created by BarthSarafin on 23.03.2015.
//


void genPrint(void * source, int numElements, char size, void (*printFunction)(void *));
//int printStruct(struct record *r);
int print(void* source, int numElements, char type);

void (*printFunction)(void*);

typedef enum {
    STRING, INT, CHAR, FLOAT
} type;

struct record{
    void* source;
    type t;
    struct record* previousRecord;
};


