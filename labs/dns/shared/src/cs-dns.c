#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "lib/tdns/tdns-c.h"

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

    /* PART 1 TODO: Implement a DNS nameserver for the cs.utexas.edu zone */

    /* 1. Create a **UDP** socket */

    /* 2. Initialize the server address (INADDR_ANY, DNS_PORT) */
    /*    and bind the socket to this address. */

    /* 3. Initialize a TDNS server context using TDNSInit(). */
    /*    This context will be used for all subsequent TDNS library calls. */

    /* 4. Create the cs.utexas.edu zone with TDNSCreateZone(). */
    /*    - Add an A record for cs.utexas.edu using TDNSAddRecord(). */
    /*    - Add an A record for aquila.cs.utexas.edu. */

    /* 5. Enter a loop to receive incoming DNS messages */
    /*    and parse each message using TDNSParseMsg(). */

    /* 6. If the message is a query for A, AAAA, or NS records: */
    /*      - Look up the record with TDNSFind() and send a response. */
    /*    Otherwise, ignore the message. */

    return 0;
}
