//
// Created by BarthSarafin on 23.03.2015.
//


void genPrint(void * source, int numElements, char size, void (*printFunction)(void *));
int printStruct(struct RECORD *r);
void print(void* source, int numElements, char type);

void (*printFunction)(void*);

typedef enum {
    STRING, INT, CHAR, FLOAT
} type;

typedef struct RECORD{
    void* source;
    int numElements;
    type t;
    struct RECORD* previousRecord;
} RECORD;


