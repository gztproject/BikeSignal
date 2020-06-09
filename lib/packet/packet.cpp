#include "packet.h"

packet::packet(byte *payload)
{
    packetId = payload[0];
    packetTtl = payload[1];
    packetCommand = payload[2];
}

packet::packet(uint8_t id, uint8_t ttl, uint8_t type, uint8_t command, uint8_t arg)
{
    packetId = constrain(id, 0, 0xFF);
    packetTtl = constrain(ttl, 0, 0xFF);
    if (type == SYNC)
        packetCommand = constrain(type, 0b000, 0b111) << 5 + constrain(arg, 0b00000, 0b11111);
    if (type == COMMAND)
        packetCommand = constrain(type, 0b000, 0b111) << 5 + constrain(command, 0b00, 0b11) << 3 + constrain(arg, 0b000, 0b111);
}

packet::packet(uint8_t id, uint8_t ttl, uint8_t type, uint8_t arg)
{
    packetId = constrain(id, 0, 0xFF);
    packetTtl = constrain(ttl, 0, 0xFF);
    packetCommand = constrain(type, 0b000, 0b111) << 5 + constrain(arg, 0b00000, 0b11111);
}

packet::packet(packet_s packet)
{
    packetId = constrain(packet.id, 0, 0xFF);
    packetTtl = constrain(packet.ttl, 0, 0xFF);
    if (packet.type == SYNC)
        packetCommand = constrain(packet.type, 0b000, 0b111) << 5 + constrain(packet.arg, 0b00000, 0b11111);
    if (packet.type == COMMAND)
        packetCommand = constrain(packet.type, 0b000, 0b111) << 5 + constrain(packet.cmd, 0b00, 0b11) << 3 + constrain(packet.arg, 0b000, 0b111);
}

void packet::getPayload(byte *payload)
{
    payload[0] = packetId;
    payload[1] = packetTtl;
    payload[2] = packetCommand;
}

packet_s packet::getStruct()
{
    packet_s pack = {getId(), getTtl(), getType(), getCommand(), getArg()};
    return pack;
}

uint8_t packet::getId()
{
    return packetId;
}

uint8_t packet::getTtl()
{
    return packetTtl;
}

uint8_t packet::getType()
{
    return packetCommand >> 5;
}

uint8_t packet::getCommand()
{
    if (getType() == SYNC)
        return SYNC_ARG;
    return (packetCommand >> 3) & 0b00011;
}

uint8_t packet::getArg()
{
    if (getType() == SYNC)
        return packetCommand & 0b00011111;
    return packetCommand & 0b00000111;
}

uint8_t packet::decreaseTtl()
{
    packetTtl -= 1;
    return getTtl();
}

void packet::debug()
{
    Serial.printf("\n\rID: %u, TTL: %u, TYPE: %u, CMD: %u, ARG: %u", getId(), getTtl(), getType(), getCommand(), getArg());
}
