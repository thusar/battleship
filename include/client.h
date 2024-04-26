#ifndef _CLIENT_H
#define _CLIENT_H

#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include "socket.h"

#include <iostream>

class Client
{
private:
    int _clientSocket;
    sockaddr_in _sockaddr;
public:
    Client();
    void report(const std::string& msg, int terminate);
    void write(const std::string& msg);
    std::string read();
    
};

#endif