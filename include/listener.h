#ifndef _LISTENER_H
#define _LISTENER_H

#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <iostream>

class Listener
{
private:
    int _listenerSocket;
    sockaddr_in _sockaddr; 
public:
    Listener(int listenerSocket, sockaddr_in sockaddr);
    int get_listener_socket() { return _listenerSocket; }
    void report(const std::string& msg, int terminate);
    std::string read();
    void write();    
};

#endif