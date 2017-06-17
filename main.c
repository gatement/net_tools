#include<stdio.h>
#include<arpa/inet.h>
#include<netinet/ip_icmp.h>   //Provides declarations for icmp header
#include<netinet/udp.h>   //Provides declarations for udp header
#include<netinet/tcp.h>   //Provides declarations for tcp header
#include<netinet/ip.h>    //Provides declarations for ip header
#include<netinet/if_ether.h>  //For ETH_P_ALL
#include<net/ethernet.h>  //For ether_header
#include "util.h"

int main(void)
{
  int sock_raw = socket(AF_INET , SOCK_RAW , IPPROTO_TCP);
  unsigned char buffer[1024] = {0};
  struct sockaddr_in saddr;
  int saddr_size = sizeof(saddr);
  int data_size = 0;

  while(data_size == 0) {
    data_size = recvfrom(sock_raw, buffer, sizeof(buffer), 0, (struct sockaddr *)&saddr, &saddr_size);
  }

  printf("%u\n", data_size);
  print_buf((void *)buffer, data_size);

  return 0;
}

