#include "../include/client.h"
#include "../include/socket.h"

void Client::report(const std::string& msg, int terminate) {
  perror(msg.c_str());
  if (terminate) exit(-1); /* failure */
}

Client::Client()
{
    /* fd for the socket */
    int sockfd = socket(AF_INET,      /* versus AF_LOCAL */
		                SOCK_STREAM,  /* reliable, bidirectional */
		                0);           /* system picks protocol (TCP) */
    if (sockfd < 0) report("socket", 1); /* terminate */

    /* get the address of the host */
    hostent* hptr = gethostbyname(HOST.c_str()); /* localhost: 127.0.0.1 */ 
    if (!hptr) report("gethostbyname", 1); /* is hptr NULL? */
    if (hptr->h_addrtype != AF_INET)       /* versus AF_LOCAL */
        report("bad address family", 1);
  
    /* connect to the server: configure server's address 1st */
    sockaddr_in saddr{};
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = 
        ((struct in_addr*) hptr->h_addr_list[0])->s_addr;
    saddr.sin_port = htons(PORTNUMBER); /* port number in big-endian */ 

    if (connect(sockfd, (sockaddr*) &saddr, sizeof(saddr)) < 0)
        report("connect", 1);   
}

Client::write() 
{
    /* Write some stuff and read the echoes. */
    int i;
    int sockfd = socket(AF_INET,      /* versus AF_LOCAL */
		                SOCK_STREAM,  /* reliable, bidirectional */
		                0);           /* system picks protocol (TCP) */
    if (::write(sockfd, (void*)"OK", sizeof("OK")) > 0)
    {
        std::cout << "OK";            
    }
}
           
Client::read()
{
    std::string buffer{};
    int sockfd = socket(AF_INET,      /* versus AF_LOCAL */
		                SOCK_STREAM,  /* reliable, bidirectional */
		                0);           /* system picks protocol (TCP) */
    if (::read(sockfd), (void*)buffer.c_str(), sizeof(buffer) > 0)
    {
        std::cout << "OK";
    }
    
}



