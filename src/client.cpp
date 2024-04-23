#include "../include/client.h"
#include "../include/socket.h"

void Client::report(const std::string& msg, int terminate) {
  perror(msg.c_str());
  if (terminate) exit(-1); /* failure */
}

Client::Client()
{
    /* fd for the socket */
    _clientSocket = socket(AF_INET,      /* versus AF_LOCAL */
		                  SOCK_STREAM,  /* reliable, bidirectional */
		                  0);           /* system picks protocol (TCP) */
    if (_clientSocket < 0) report("socket", 1); /* terminate */

    /* get the address of the host */
    hostent* hptr = gethostbyname(HOST.c_str()); /* localhost: 127.0.0.1 */ 
    if (!hptr) report("gethostbyname", 1); /* is hptr NULL? */
    if (hptr->h_addrtype != AF_INET)       /* versus AF_LOCAL */
        report("bad address family", 1);
  
    /* connect to the server: configure server's address 1st */
    // sockaddr_in saddr{};
    _sockaddr.sin_family = AF_INET;
    _sockaddr.sin_addr.s_addr = 
        ((struct in_addr*) hptr->h_addr_list[0])->s_addr;
    _sockaddr.sin_port = htons(PORTNUMBER); /* port number in big-endian */ 

    if (connect(_clientSocket, (sockaddr*) &_sockaddr, sizeof(_sockaddr)) < 0) {
        report("connect", 1);
    } else {
        std::cout << "error";
    }
           
}

void Client::write() 
{
    /* Write some stuff and read the echoes. */
    int i;
    std::string msg{"OK"};                    
    if (::write(_clientSocket, msg.data(), msg.size()) > 0) {
        std::cout << "OK";
        std::cout << msg.data();            
    }
    else {
        std::cout << "error";
    }
}
           
void Client::read()
{
    std::string buffer{};
    if (::read(_clientSocket, (void*)buffer.c_str(), sizeof(buffer) > 0))
    {
        std::cout << "OK";
    }
    
}



