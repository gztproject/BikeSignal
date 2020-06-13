#include "packet.h"

packet::packet()
{
    packetId = 0;
    packetTtl = 0;
    packetCommand = (EMPTY << 5);
}

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
        packetCommand = (constrain(type, 0b000, 0b111) << 5) + constrain(arg, 0b00000, 0b11111);
    if (type == COMMAND)
        packetCommand = (constrain(type, 0b000, 0b111) << 5) + (constrain(command, 0b00, 0b11) << 3) + constrain(arg, 0b000, 0b111);
}

packet::packet(uint8_t id, uint8_t ttl, uint8_t arg)
{
    packetId = constrain(id, 0, 0xFF);
    packetTtl = constrain(ttl, 0, 0xFF);
    packetCommand = (SYNC << 5) + constrain(arg, 0b00000, 0b11111);
}

packet::packet(packet_s packet)
{
    packetId = constrain(packet.id, 0, 0xFF);
    packetTtl = constrain(packet.ttl, 0, 0xFF);
    if (packet.type == SYNC)
        packetCommand = (constrain(packet.type, 0b000, 0b111) << 5) + constrain(packet.arg, 0b00000, 0b11111);
    if (packet.type == COMMAND)
        packetCommand = (constrain(packet.type, 0b000, 0b111) << 5) + (constrain(packet.cmd, 0b00, 0b11) << 3) + constrain(packet.arg, 0b000, 0b111);
}

void packet::clone(packet original)
{
    packetId = original.getId();
    packetTtl = original.getTtl();
    packetCommand = (original.getType() << 5);
    if (original.getType() == SYNC)
        packetCommand += original.getArg();
    if (original.getType() == COMMAND)
        packetCommand += original.getCommand() << 3 + original.getArg();
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

uint8_t packet::setId(uint8_t id)
{
    if (getId() >= id)
        Serial.print("\n\rTrying to set lower or equal ID, ignoring.");
    else
        packetId = id;
    return getId();
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

uint8_t packet::setSyncArg(uint8_t id)
{
    if (getType() == SYNC)
    {
        Serial.print("\n\rSetting ID argument.");
        packetCommand = (SYNC << 5) + constrain(id, 0b00000, 0b11111);
    }
    else
        Serial.print("\n\rTrying to set ID argument on non SYNC packet.");
    return getArg();
}

uint8_t packet::decreaseTtl()
{
    packetTtl -= 1;
    return getTtl();
}

void packet::debug()
{
    Serial.printf("\n\rID: %u, TTL: %u, TYPE: ", getId(), getTtl());
    if (getType() == SYNC)
    {
        Serial.printf("Sync, ARG: %u", getArg());
    }
    if (getType() == COMMAND)
    {
        Serial.print("Command: ");
        if (getCommand() == REQUEST)
            Serial.print("Request");
        else if (getCommand() == CANCEL)
            Serial.print("Cancel");
        else if (getCommand() == ACKNOWLEDGE)
            Serial.print("Acknowledge");
        else if (getCommand() == CLEAR)
            Serial.print("Clear");
        else
            Serial.print("Unknown");
        Serial.printf(", ARG %u", getArg());
    }
}
