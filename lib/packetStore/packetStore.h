#ifndef PACKET_STORE_H
#define PACKET_STORE_H

#define PACKET_STORE_SIZE 0b11111

#include <Arduino.h>
#include "packet.h"

class packetStore
{

public:
    packetStore();

    void push(packet_s pack);
    void clear();
    bool isPacketKnown(packet_s pack);
    uint8_t getSize();
    uint8_t getMaxSyncId();

private:
    packet_s stack[PACKET_STORE_SIZE];
};

#endif