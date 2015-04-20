//
// Created by BarthSarafin on 20.04.2015.
//

#define IPA(p1, p2, p3, p4) (p1 << 24 | (p2 << 16) | (p3 << 8) | (p4))
#define _IPA(ip) ((ip >> 24) & 0xFF), ((ip >> 16) & 0xFF), ((ip >> 8) & 0xFF), (ip & 0xFF)
#define Default 0
#define Direct 0

typedef unsigned int u32;
typedef unsigned int u8;
typedef struct {
    u32 netAddress;
    u32 netMask;
    u8 port :8;
    u32 gateway;
} routingTable;

int printRoutingTable(const unsigned entry_cnt, routingTable rt[]);
