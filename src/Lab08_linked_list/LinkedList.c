/*
 Name        : 08_LinkedList.c
 Author      : metl@zhaw.ch
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int boolean;

// define Node
typedef struct node{
    unsigned int data; // Node data
    struct node *next; // next Node
} Node;

boolean add(unsigned int);
boolean del(unsigned int);
void list(void);

// define head (Start Node)
Node *head = NULL;

int main(int argc, char** argv) {
    (void) add(3);
    (void) add(2);
    (void) add(1);
    list();
    (void) del(3);
    list();
    (void) del(1);
    list();
    (void) del(1);
    list();

    unsigned int i = 0;
    for (i = 1; i < 1000; i++) (void) add(i);
    list();
    for (i = 999; i > 0; i--) (void) del(i);
    list();
    (void) add(123);
    (void) add(123456);
    list();
    (void) del(2);
    (void) del(1);
    for (i = 1; i < 1000; i++){
        (void) add(i);
        (void) del(1);
    }
    (void) add(456);
    list();
    (void) del(1);
    list();

    return (EXIT_SUCCESS);
}

boolean add(unsigned int data) {
    // allocate new Node
    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL) return FALSE;
    // set Node data
    new->data = data;
    // insert new Node at first position
    new->next = head;
    head = new;
    return TRUE;
}

boolean del(unsigned int index) {
    unsigned int count = 1;
    // set navigation pointer to head (Start Node)
    Node *temp = NULL, *nav = head, *del = NULL;
    // empty list (no Nodes)
    if (nav == NULL) return FALSE;
    // count Nodes
    while (nav->next != NULL) {
        count++;
        if (index == count) del = nav;
        nav = nav->next;
    }
    // if the index is out of range, exit
    if (index < 1 || index > count) return FALSE;
    // re-set head when index = 1
    if (index == 1) {
        temp = head;
        head = head->next;
        free(temp);
        return TRUE;
    }
    // drop last node when index = count
    if (index == count){
        temp = del->next;
        del->next = NULL;
        free(temp);
        return TRUE;
    }
    // save node to be deleted
    temp = del->next;
    // skip node to be deleted
    del->next = del->next->next;

    // now free the memory from the deleted node
    free(temp);
    return TRUE;
}

void list(void) {
    // set navigation pointer to head (Start Node)
    Node *nav = head;
    // count Nodes
    unsigned int count = 0, i = 0;
    while (nav != NULL) {
        count++;
        nav = nav->next;
    }
    // print header
    (void) printf("%3u items ", count);
    for (i = 0; i < count; i++) {
        (void) printf("->[-address:----data,----next]");
    }
    (void) printf("\n<%p>", head);
    // set navigation pointer to head (Start Node)
    nav = head;
    // print Node data
    while (nav != NULL) {
        (void) printf("->[%p:%8u,%p]",nav, nav->data, nav->next);
        nav = nav->next;
    }
    (void) printf("\n\n");
}