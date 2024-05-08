#include <cstddef>


#include "../include/listener.h"
#include "../include/socket.h"

#include <ctime>

void Listener::report(const std::string& msg, int terminate) {
  perror(msg.c_str());
  std::cout << msg << std::endl;
  if (terminate) exit(-1); /* failure */
}

Listener::Listener(std::pair<std::string, int>, std::vector<std::byte>)
{
    /* fd for the socket */
    _listenerSocket = socket(AF_INET,      /* versus AF_LOCAL */
		                     SOCK_STREAM,  /* reliable, bidirectional */
		                     0);           /* system picks protocol (TCP) */
    if (_listenerSocket < 0) report("socket error", 1); /* terminate */

    /* get the address of the host */
    hostent* hptr = gethostbyname(HOST.c_str()); /* localhost: 127.0.0.1 */ 
    if (!hptr) report("gethostbyname error", 1); /* is hptr NULL? */
    if (hptr->h_addrtype != AF_INET)       /* versus AF_LOCAL */
        report("bad address family", 1);
  
    /* connect to the server: configure server's address 1st */
    sockaddr_in ipSocketAddress{AF_INET, htons(PORTNUMBER), inet_addr("127.0.0.1"), };

    int connectReturn = connect(_listenerSocket, (sockaddr*) &ipSocketAddress, sizeof(sockaddr));
}

sockaddr_in Listener::accept()
{
    socklen_t len = sizeof(_listenerSocket);
    int clientSocket = ::accept(_listenerSocket, (sockaddr*)& _listenerSocket, &len);
    return clientSocket;
}

std::string Listener::read()
{
    char buffer[1024] = {0};
    ssize_t readReturn = recv(_listenerSocket, buffer, sizeof(buffer), 0);
    return std::string(buffer);
}

void Listener::write(std::string& msg)
{
     std::srand(std::time(nullptr));
     std::uint8_t integerOne = std::rand() / ((RAND_MAX + 1u) / 2); // 1 or 2
     if (integerOne == 1)
        msg = std::string("x");
     else
        msg = std::string("o");  
     ssize_t writeReturn = ::write(_listenerSocket, msg.data(), msg.size()); /* echo as confirmation */
}


