#include "../include/client.h"
#include "../include/socket.h"

void Client::report(const std::string& msg, int terminate) {
  perror(msg.c_str());
  std::cout << msg;  
  if (terminate) exit(-1); /* failure */
}

Client::Client(std::string ip, int portNumber)
{
    /* fd for the socket */
    _clientSocket = socket(AF_INET,      /* versus AF_LOCAL */
		                  SOCK_STREAM,  /* reliable, bidirectional */
		                  0);           /* system picks protocol (TCP) */
    if (_clientSocket < 0) report("socket error", 1); /* terminate */

    /* get the address of the host */
    hostent* hptr = gethostbyname(HOST.c_str()); /* localhost: 127.0.0.1 */ 
    if (!hptr) report("gethostbyname error", 1); /* is hptr NULL? */
    if (hptr->h_addrtype != AF_INET)       /* versus AF_LOCAL */
        report("bad address family", 1);
  
    /* connect to the server: configure server's address 1st */
    sockaddr_in ipSocketAddress{AF_INET, htons(PORTNUMBER), inet_addr("127.0.0.1"), };

    int connectReturn = connect(_clientSocket, (sockaddr*) &ipSocketAddress, sizeof(sockaddr));
           
}

void Client::write(const std::string& msg) 
{
    /* Write some stuff and read the echoes. */
    ssize_t writeReturn = ::write(_clientSocket, msg.data(), msg.size());
}
           
std::string Client::read()
{
    char buffer[1024] = {0};
    ssize_t readReturn = recv(_clientSocket, buffer, sizeof(buffer), 0);
    return std::string(buffer);
}



