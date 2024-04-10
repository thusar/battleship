#ifndef SOCKET_H
#define SOCKET_H
#include <cstdint>
#include <string>
#include <functional>

class Socket
{
private:
    int sockfd;
    int connfd;
    uint16_t port;
    struct sockaddr_in* servaddr;
    std::string ip;
    bool verbose;  
public:
    Socket(const std::string & _ip = "0.0.0.0", uint16_t _port=8080, bool verbose=false);

    ~Socket();

    ssize_t read(std::string buff, size_t len);
    ssize_t write(std::string buff, size_t len);

    std::string read();
    void write(std::string str);

    uint64_t read_uint64();
    uint8_t read_uint8();

    void write_uint64(const uint64_t& value);
    void write_uint8(const uint8_t& value);


};

#endif