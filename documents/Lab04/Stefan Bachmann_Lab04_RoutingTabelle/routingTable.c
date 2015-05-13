//
// Created by BarthSarafin on 20.04.2015.
//

#include "routingTable.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int option = 1;
    while(option) {
        (void) printf("######################################\n");
        (void) printf("#            PROG C                  #\n");
        (void) printf("#            bachmste                #\n");
        (void) printf("#            routing table           #\n");
        (void) printf("######################################\n\n");

        const unsigned entryCount = sizeof(rt) / sizeof(routingTable);
        (void) printRoutingTable(entryCount, rt);
        (void) printf("Would you like to continue? [0/1]?\n");
        (void) scanf("%d", &option);
        fflush(stdin);
    }
    return EXIT_SUCCESS;
}

int printRoutingTable(const unsigned entryCount, routingTable rt[]) {
    int i;
    (void) printf("Netadress\t   Gateway \t\tPort     Netmask\n");
    (void) printf("----------------------------------------------------------------------------\n");
    for(i=0; i < entryCount; i++) {
        (void) printf("%u.%u.%u.%u \t-> %u.%u.%u.%u \t\t %u\t %u.%u.%u.%u\n", _IPA(rt[i].netAddress),
                      _IPA(rt[i].gateway), rt[i].port, _IPA(rt[i].netMask));
    }
    (void) printf("----------------------------------------------------------------------------\n");

    return EXIT_SUCCESS;
}
