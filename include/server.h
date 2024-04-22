#ifndef _SERVER_H
#define _SERVER_H

#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <iostream>


class Server
{
private:
public:
    Server();
    void report(const std::string& msg, int terminate);
    void read();
    void write(int count);
};

#endif