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
public:
    Client();
    void report(const std::string& msg, int terminate);
    void read();
    void write(int count);
};

#endif