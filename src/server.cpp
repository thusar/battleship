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
        
    if (_serverSocket < 0) report(std::string("socket"), 1); /* terminate */
  	
    /* bind the server's local address in memory */
    
    //memset(&saddr, 0, sizeof(saddr));          /* clear the bytes */
    _sockaddr.sin_family = AF_INET;                /* versus AF_LOCAL */
    _sockaddr.sin_addr.s_addr = htonl(INADDR_ANY); /* host-to-network endian */
    _sockaddr.sin_port = htons(PORTNUMBER);        /* for listening */
  
    if (bind(_serverSocket, (sockaddr*)(&_sockaddr), sizeof(_sockaddr)) < 0)
        report("bind", 1); /* terminate */
	
    /* listen to the socket */
    if (listen(_serverSocket, MAXCONNECTS) < 0) /* listen for clients, up to MaxConnects */
        report("listen", 1); /* terminate */

    std::cerr << "Listening on port " << PORTNUMBER << " for clients...\n";
    /* a server traditionally listens indefinitely */
    while (1) {
        sockaddr_in caddr; /* client address */
        socklen_t len = sizeof(caddr);  /* address length could change */
    
        int clientSocket = accept(_serverSocket, (sockaddr*)&caddr, &len);  /* accept blocks */
        if (clientSocket < 0) {
            report("accept", 0); /* don't terminated, though there's a problem */
            continue;
        }
    }        
}

std::string Server::read()
{
    while (1) {
        int i;
        std::string msg{};
        _serverSocket = socket(AF_INET,     /* network versus AF_LOCAL */
	                           SOCK_STREAM, /* reliable, bidirectional: TCP */
		                       0);          /* system picks underlying protocol */
        ssize_t readReturn = ::read(_serverSocket, (void*)msg.data(), msg.size());
    }
    
}

void Server::write(const std::string& msg)
{
    while (1) {
        std::string buffer{};
        _serverSocket = socket(AF_INET,     /* network versus AF_LOCAL */
	                           SOCK_STREAM, /* reliable, bidirectional: TCP */
		                       0);          /* system picks underlying protocol */
        std::string msg{"OK"};
        ssize_t writeReturn = ::write(_serverSocket, msg.data(), msg.size()); /* echo as confirmation */
    }
}