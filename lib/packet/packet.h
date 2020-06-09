#ifndef PACKET_H
#define PACKET_H

#include <Arduino.h>

/*
 * Packet structure:
 * _______________________________________________________________________________________________________________________________________________
 * |                                                                  PACKET (3B)                                                                 |
 * |                             HEADER (2B)                        |                              COMMAND (1B)                            |
 * |           ID (1B)             |                TTL (1B)        |                                                                      |           
 * |           ID (8b)             |            MAX TTL (8b)        |    TYPE (3b)               |        CMD/ARG (5b)                     |
 * |                               |                                | 0 | X | X | SYNC           | A | B | C | D | E | ID n(ABCDE)         |
 * |                               |                                | 1 | X | X | COMANND        | 0 | 0 | A | B | C | REQUEST n(ABC)      |
 * | A B C D E F G H | n(ABCDEFGH) | A B C D E F G H | n(ABCDEFGH)  | 1 | X | X | COMMAND        | 0 | 1 | A | B | C | CANCEL  n(ABC)      |
 * |                               |                                | 1 | X | X | COMMAND        | 1 | 0 | A | B | C | ACKNOWLEDGE  n(ABC) |
 * |                               |                                | 1 | X | X | COMMAND        | 1 | 1 | X | X | X | RESERVED            |
 * |_______________________________________________________________________________________________________________________________________|
 */

#define PACKET_SIZE 3
#define TTL 0b11111

struct packet_s
{
    uint8_t id;
    uint8_t ttl;
    uint8_t type;
    uint8_t cmd;
    uint8_t arg;
};

class packet
{

public:
    /**
     * Initialize - encode a command packet
     */
    packet(uint8_t id, uint8_t ttl, uint8_t type, uint8_t command, uint8_t arg);
    /**
     * Initialize - encode a sync packet
     */
    packet(uint8_t id, uint8_t ttl, uint8_t type, uint8_t arg);
    /**
     * Initialize - encode a packet from the struct
     */
    packet(packet_s packet);
    /**
     * Initialize - decode packet from payload
     */
    packet(byte *payload);    

    /**
     * Write packet payload into a TX buffer      
     */
    void getPayload(byte *payload);
    /**
     * Write the packet into a struct
     */
    packet_s getStruct();

    uint8_t getId();
    uint8_t getTtl();
    uint8_t getType();
    uint8_t getCommand();
    uint8_t getArg();

    uint8_t decreaseTtl();

    void debug();

private:
    uint8_t packetId;
    uint8_t packetTtl;
    uint8_t packetCommand;
};

typedef enum
{
    SYNC = 0b000,
    COMMAND = 0b100
} types;

typedef enum
{
    REQUEST = 0b00,
    CANCEL = 0b01,
    ACKNOWLEDGE = 0b10,
    RESERVED = 0b11,
    SYNC_ARG = 255
} commands;

#endif