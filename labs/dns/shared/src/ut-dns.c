#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "lib/tdns/tdns-c.h"
#include <stdbool.h>

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

    /* PART 1 TODO: Implement a DNS nameserver for the utexas.edu zone */

    /* 1. Create a UDP socket. */
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    /* 2. Initialize the server address (INADDR_ANY, DNS_PORT) */
    /*    and bind the socket to this address. */
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(DNS_PORT);

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    /* 3. Initialize a TDNS server context using TDNSInit(). */
    /*    This context will be used for all subsequent TDNS library calls. */

    struct TDNSServerContext *tdns_ctx = TDNSInit();

    /* 4. Create the utexas.edu zone with TDNSCreateZone(). */
    /*    - Add an A record for www.utexas.edu using TDNSAddRecord(). */
    /*    - Add an NS record for the UTCS nameserver ns.cs.utexas.edu. */
    /*    - Add an A record for ns.cs.utexas.edu. */

    TDNSCreateZone(tdns_ctx, "utexas.edu");
    TDNSAddRecord(tdns_ctx, "utexas.edu", "www", "40.0.0.10", NULL);
    TDNSAddRecord(tdns_ctx, "utexas.edu", "cs", NULL, "ns.cs.utexas.edu");
    TDNSAddRecord(tdns_ctx, "cs.utexas.edu", "ns", "50.0.0.30", NULL);

    /* 5. Enter a loop to receive incoming DNS messages */
    /*    and parse each message using TDNSParseMsg(). */

    struct TDNSParseResult parsed;
    bool is_response = false;

    while (true) { 
        ssize_t size = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &client_len);
        is_response = TDNSParseMsg(buffer, size, &parsed);

            /* 6. If the message is a query for A, AAAA, or NS records: */
            /*      - Look up the record with TDNSFind() and send a response. */
            /*    Otherwise, ignore the message. */

            struct TDNSFindResult result;
            if (!is_response) {
                if (parsed.qtype == A || parsed.qtype == AAAA || parsed.qtype == NS) {
                    TDNSFind(tdns_ctx, &parsed, &result);
                    sendto(sockfd, result.serialized, result.len, 0, (struct sockaddr *)&client_addr, client_len);
                }
            }

    }
    
    return 0;
}
