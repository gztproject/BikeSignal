#include "packetStore.h"

packetStore::packetStore()
{
    Serial.printf("\n\n\n\n\rInitializing packet store:");
    clear();
}

void packetStore::push(packet_s pack)
{
    Serial.printf("\n\rPushing the packet on the stack...");
    for (int i = PACKET_STORE_SIZE - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            stack[i] = pack;
        }
        else
        {
            stack[i] = stack[i - 1];
        }
    }
}

void packetStore::clear()
{
    for (int i = 0; i < PACKET_STORE_SIZE; i++)
    {
        stack[i] = {0, 0, 0, 0, 0};
    }
}

bool packetStore::isPacketKnown(packet_s pack)
{
    Serial.printf("\n\rChecking the packet store for known packets...");
    for (int i = 0; i < PACKET_STORE_SIZE; i++)
    {
        if (stack[i].id == pack.id && stack[i].type == pack.type && stack[i].cmd == pack.cmd && stack[i].arg == pack.arg)
        {
            Serial.print(" Found one!");
            return true;
        }
    }
    Serial.print(" Nothing here!");
    return false;
}

uint8_t packetStore::getSize()
{
    uint8_t n = 0;
    for (int i = 0; i < PACKET_STORE_SIZE; i++)
    {
        n = stack[i].ttl > 0 ? n + 1 : n;
    }
    return n;
}

uint8_t packetStore::getMaxSyncId()
{
    uint8_t id = 0;
    for (int i = 0; i < PACKET_STORE_SIZE; i++)
    {
        if (stack[i].ttl > 0)
            id = stack[i].arg > id ? stack[i].arg : id;
    }
    return constrain(id, 0, PACKET_STORE_SIZE - 1);
}