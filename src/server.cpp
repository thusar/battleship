#include "../include/server.h"
#include "../include/socket.h"

void Server::report(const std::string& msg, int terminate) {
  perror(msg.c_str());
  if (terminate) exit(-1); /* failure */
}

Server::Server()
{
    int fd = socket(AF_INET,     /* network versus AF_LOCAL */
	                SOCK_STREAM, /* reliable, bidirectional: TCP */
		            0);          /* system picks underlying protocol */
        
    if (fd < 0) report(std::string("socket"), 1); /* terminate */
  	
    /* bind the server's local address in memory */
    sockaddr_in saddr{};
    //memset(&saddr, 0, sizeof(saddr));          /* clear the bytes */
    saddr.sin_family = AF_INET;                /* versus AF_LOCAL */
    saddr.sin_addr.s_addr = htonl(INADDR_ANY); /* host-to-network endian */
    saddr.sin_port = htons(PORTNUMBER);        /* for listening */
  
    if (bind(fd, (sockaddr*)(&saddr), sizeof(saddr)) < 0)
        report("bind", 1); /* terminate */
	
    /* listen to the socket */
    if (listen(fd, MAXCONNECTS) < 0) /* listen for clients, up to MaxConnects */
        report("listen", 1); /* terminate */

    std::cerr << "Listening on port " << PORTNUMBER << "for clients...\n";
    /* a server traditionally listens indefinitely */
    while (1) {
        sockaddr_in caddr; /* client address */
        socklen_t len = sizeof(caddr);  /* address length could change */
    
        int client_fd = accept(fd, (sockaddr*)&caddr, &len);  /* accept blocks */
        if (client_fd < 0) {
            report("accept", 0); /* don't terminated, though there's a problem */
            continue;
        }
    }        
}

void Server::read()
{
    while (1) {
        int i;
        for (i = 0; i < CONVERSATIONLEN; ++i) {
            std::string buffer{};
            int fd = socket(AF_INET,     /* network versus AF_LOCAL */
	                        SOCK_STREAM, /* reliable, bidirectional: TCP */
		                    0);          /* system picks underlying protocol */
            ::read(fd, (void*)(buffer.c_str()), sizeof(buffer));
        }
    }
    
}

void Server::write(int count)
{
    while (1) {
        if (count > 0) {
            std::string buffer{};
            int fd = socket(AF_INET,     /* network versus AF_LOCAL */
	                        SOCK_STREAM, /* reliable, bidirectional: TCP */
		                    0);          /* system picks underlying protocol */
	        ::write(fd, (void*)(buffer.c_str()), sizeof(buffer)); /* echo as confirmation */
        }
    }
}