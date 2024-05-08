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
#include <iostream>

#include "../include/socket.h" // constants

class Client
{
private:
    int _clientSocket;
    
public:
    Client(std::string ip, int clientFileDescriptor);
    void report(const std::string& msg, int terminate);
    void write(const std::string& msg);
    std::string read();
    
};

#endif