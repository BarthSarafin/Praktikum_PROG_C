//
// Created by BarthSarafin on 20.04.2015.
//

#include "routingTable.h"
#include <stdio.h>
#include <stdlib.h>

routingTable rt[] = {
        {IPA(160, 85, 18, 0), IPA(255, 255, 255, 240), 1, Direct},
        {IPA(160, 85, 19, 0), IPA(255, 255, 255, 0), 2, Direct},
        {IPA(160, 85, 16, 0), IPA(255, 255, 254, 0), 0, Direct},
        {Default, Default, 0, IPA(160, 85, 16, 1)}
};

int main(void) {
    const unsigned entry_cnt = sizeof(rt) / sizeof(routingTable);
    (void) printRoutingTable(entry_cnt, rt);
    return EXIT_SUCCESS;
}

int printRoutingTable(const unsigned entry_cnt, routingTable rt[]) {
    int i;
    printf("Netadress\t   Gateway \t\tPort     Netmask\n");
    printf("----------------------------------------------------------------------------\n");
    for(i=0; i<entry_cnt; i++) {
        (void) printf("%u.%u.%u.%u \t-> %u.%u.%u.%u \t\t %u\t %u.%u.%u.%u\n", _IPA(rt[i].netAddress),
                      _IPA(rt[i].gateway), rt[i].port, _IPA(rt[i].netMask));
    }
    printf("----------------------------------------------------------------------------\n");

    return EXIT_SUCCESS;
}
