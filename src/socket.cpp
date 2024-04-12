#include <iostream>
#include <stdexcept>
#include <string>

#include "include/socket.h"

Socket::Socket(const std::string & _ip, uint16_t _port, bool _verbose)
  : ip(_ip), port(_port), verbose(_verbose)
{
    socklen_t len;
    servaddr = nullptr;

    // socket create and verification 
    sockfd = std::socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) {
        throw std::runtime_error("socket creation failed");
    } else {
        if(verbose) {
            std::cout << "Socket successfully created" << std::endl;
        }
    }
    servaddr = std::make_shared<struct sockaddr_in>;
    bzero(servaddr, sizeof(struct sockaddr_in)); 
  
    // assign IP, PORT 
    servaddr->sin_family = AF_INET;
    if(ip == "0.0.0.0")
    {
        servaddr->sin_addr.s_addr = htonl(INADDR_ANY);
    }
    else
    {
        servaddr->sin_addr.s_addr = inet_addr(ip.c_str());
    }
    servaddr->sin_port = htons(port); 
}


Socket::~Socket()
{
    // After chatting close the socket 
    close(sockfd);
}

ssize_t Socket::read(std::string buffer)
{
  return ::read(connfd, buffer, std::length(buffer));
}

ssize_t Socket::write(std::string buffer)
{
  return ::write(connfd, buffer, std::length(buffer));
}

std::string Socket::read()
{
  std::size_t len = this->read_uint64();
  std::string charArray{};
  this->read(charArray);
  return charArray;
}

void Socket::write(std::string str)
{
  uint64_t len = std::size(str);
  this->write_uint64(len);
  this->write(str, std::size(str));
}

uint64_t Socket::read_uint64()
{
  std::string buffer{};
  this->read(&buffer, 1);
  return (uint64_t)buff;
}

uint8_t Socket::read_uint8()
{
  char buff;
  this->read(&buff, 1);
  return (uint8_t)buff;
}

void Socket::write_uint64(const uint64_t& value)
{
  this->write((const char*)&value, 1);
}

void Socket::write_uint8(const uint8_t& value)
{
  this->write((const char*)&value, 1);
}