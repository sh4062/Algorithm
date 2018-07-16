#include "fun.h"

/** 
 * Read input from command line
 */
void read_input(char* buffer, int size)
{
	char *nl = NULL;
	memset(buffer, 0, size);

	if ( fgets(buffer, size, stdin) != NULL ) {
		nl = strchr(buffer, '\n');
		if (nl) *nl = '\0'; // truncate, ovewriting newline
	}
}

/**
 * Send resposne code on sockfd
 * Returns -1 on error, 0 on success
 */
int send_response(int sockfd, int rc)
{
	int conv = htonl(rc);
	if (send(sockfd, &conv, sizeof conv, 0) < 0 ) {
		perror("error sending...\n");
		return -1;
	}
	return 0;
}

