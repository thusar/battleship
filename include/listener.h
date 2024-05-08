#ifndef _LISTENER_H
#define _LISTENER_H

#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstddef>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#include "../include/socket.h" // constants
#include "../include/server.h" // constants


class Listener
{
private:
    std::pair<std::string, int portNumber> _listenerSocket; 
    std::vector<std::bytes> _bytes;
 
public:
    Listener(std::pair<std::string, int>, std::vector<std::bytes> bytes);
    void report(const std::string& msg, int terminate);
    sockaddr_in accept();
    std::string read();
    void write(std::string& msg);
    int get_listener_socket() { return _listenerSocket; } // for usage in server constructor     
};

#endif