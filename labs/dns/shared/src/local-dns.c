#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "lib/tdns/tdns-c.h"

/* DNS header structure */
struct dnsheader {
        uint16_t        id;         /* query identification number */
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
                        /* fields in third byte */
        unsigned        qr: 1;          /* response flag */
        unsigned        opcode: 4;      /* purpose of message */
        unsigned        aa: 1;          /* authoritative answer */
        unsigned        tc: 1;          /* truncated message */
        unsigned        rd: 1;          /* recursion desired */
                        /* fields in fourth byte */
        unsigned        ra: 1;          /* recursion available */
        unsigned        unused :1;      /* unused bits (MBZ as of 4.9.3a3) */
        unsigned        ad: 1;          /* authentic data from named */
        unsigned        cd: 1;          /* checking disabled by resolver */
        unsigned        rcode :4;       /* response code */
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
                        /* fields in third byte */
        unsigned        rd :1;          /* recursion desired */
        unsigned        tc :1;          /* truncated message */
        unsigned        aa :1;          /* authoritative answer */
        unsigned        opcode :4;      /* purpose of message */
        unsigned        qr :1;          /* response flag */
                        /* fields in fourth byte */
        unsigned        rcode :4;       /* response code */
        unsigned        cd: 1;          /* checking disabled by resolver */
        unsigned        ad: 1;          /* authentic data from named */
        unsigned        unused :1;      /* unused bits (MBZ as of 4.9.3a3) */
        unsigned        ra :1;          /* recursion available */
#endif
                        /* remaining bytes */
        uint16_t        qdcount;    /* number of question records */
        uint16_t        ancount;    /* number of answer records */
        uint16_t        nscount;    /* number of authority records */
        uint16_t        arcount;    /* number of resource records */
};

/* A few macros that might be useful */
/* Feel free to add macros you want */
#define DNS_PORT 53
#define BUFFER_SIZE 2048

int main() {
    /* A few variable declarations that might be useful */
    /* You can add anything you want */
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    /* PART 2 TODO: Implement a local iterative DNS server */

    /* 1. Create a UDP socket. */

    /* 2. Initialize the server address (INADDR_ANY, DNS_PORT) */
    /*    and bind the socket to this address. */

    /* 3. Initialize a TDNS server context using TDNSInit(). */
    /*    This context will be used for all TDNS library calls. */

    /* 4. Create the edu zone with TDNSCreateZone(). */
    /*    - Add the UT nameserver ns.utexas.edu using TDNSAddRecord(). */
    /*    - Add an A record for ns.utexas.edu using TDNSAddRecord(). */

    /* 5. Continuously receive incoming DNS messages */
    /*    and parse them using TDNSParseMsg(). */

    /* 6. If the message is a query for A, AAAA, or NS records: */
    /*      - Look up the record using TDNSFind(). */
    /*      - Ignore all other query types. */

    /*      a. If the record exists and indicates delegation: */
    /*         - Send an iterative query to the delegated nameserver. */
    /*         - Store per-query context using putAddrQID() and putNSQID() */
    /*           for future response handling. */

    /*      b. If the record exists and does NOT indicate delegation: */
    /*         - Send a direct response back to the client. */

    /*      c. If the record does not exist: */
    /*         - Send a response indicating no matching record. */

    /* 7-1. If the message is an authoritative response (i.e., contains an answer): */
    /*      - Add the NS information to the response using TDNSPutNStoMessage(). */
    /*      - Retrieve the original client address and NS info using */
    /*        getAddrbyQID() and getNSbyQID(). */
    /*      - Send the completed response to the client. */
    /*      - Delete the per-query context using delAddrQID() and delNSQID(). */

    /* 7-2. If the message is a non-authoritative response */
    /*      (i.e., a referral to another nameserver): */
    /*      - Extract the next iterative query using TDNSGetIterQuery(). */
    /*      - Forward the iterative query to the referred nameserver. */
    /*      - Update the per-query context using putNSQID(). */

    return 0;
}
