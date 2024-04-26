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
    std::string _ip{"0.0.0.0"};
    int  _listenerFileDescriptor{socket(AF_INET, SOCK_STREAM, 0)}; 
public:
    Listener(std::string ip, int listenerFileDescriptor);
    // int get_listener_socket() { return _listenerSocket; }
    int accept();
    //void report(const std::string& msg, int terminate);
    //std::string read();
    //void write();    
};

#endif