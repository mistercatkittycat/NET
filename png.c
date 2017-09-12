#define      _GNU_SOURCE
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int
ping(char *ipaddr) {
  char *command = NULL;
  FILE *fp;
  int stat = 0;
  asprintf (&command, "%s %s -q 2>&1", "fping", ipaddr);
  fp = popen(command, "r");
  if (fp == NULL) {
    fprintf(stderr, "Failed to execute fping command\n");
    free(command);
    return -1;
  }
  stat = pclose(fp);
  free(command);
  return WEXITSTATUS(stat);
}

/*  Check if an ip address is valid */
int isValidIpAddress(char *ipaddr)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipaddr, &(sa.sin_addr));
    return result != 0;
}


int main(int argc, char **argv) {
  int status = 0;
  if(argc != 2) {
    printf("Example Usage: %s 192.168.1.1\n", argv[0]);
    return 1;
  } else if(!isValidIpAddress(argv[1])) {
    printf("%s is an invalid IP Address\n", argv[1]);
    return 1;
  }
  status = ping(argv[1]);
  if (status) {
    printf("Could ping %s successfully, status %d\n", argv[1], status);
  } else {
    printf("Machine not reachable, status %d\n", status);
  }
  return status;
}
