#include "../include/server.h"
#include "../include/socket.h"

void Server::report(const std::string& msg, int terminate) {
  perror(msg.c_str());
  
  if (terminate) exit(-1); /* failure */
}

Server::Server()
{
    _serverSocket = socket(AF_INET,     /* network versus AF_LOCAL */
	                          SOCK_STREAM, /* reliable, bidirectional: TCP */
		                      0);          /* system picks underlying protocol */
    if (_serverSocket < 0) report(std::string("socket error "), 1); /* terminate */
    /* bind the server's local address in memory */
    
    _sockaddr.sin_family = AF_INET;                /* versus AF_LOCAL */
    _sockaddr.sin_addr.s_addr = htonl(INADDR_ANY); /* host-to-network endian */
    _sockaddr.sin_port = htons(PORTNUMBER);        /* for listening */
    if (bind(_serverSocket, (sockaddr*)(&_sockaddr), sizeof(_sockaddr)) < 0)
        report("bind error ", 1); /* terminate */
    /* listen to the socket */
    if (listen(_serverSocket, MAXCONNECTS) < 0) /* listen for clients, up to MaxConnects */
        report("listen error", 1); /* terminate */
}

std::string Server::read()
{
    
        int i;
        socklen_t len = sizeof(_sockaddr);  /* address length could change */
        int clientSocket = accept(_serverSocket, (sockaddr*)&_sockaddr, &len);  /* accept blocks */
        if (clientSocket < 0) {
            report("accept error", 0); /* don't terminated, though there's a problem */
        }
        char buffer[1024] = {0};
        ssize_t readReturn = recv(clientSocket, buffer, sizeof(buffer), 0);
        return std::string(buffer);
}

void Server::write(const std::string& msg)
{
        ssize_t writeReturn = ::write(_serverSocket, msg.data(), msg.size()); /* echo as confirmation */

}