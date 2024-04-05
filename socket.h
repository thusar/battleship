#pragma once
#include <cstdint>
#include <string>
#include <functional>

class Socket
{
public:
  Socket(const std::string & _ip = "0.0.0.0",
         uint16_t _port=8080,
         bool verbose=false);

  ~Socket();
  void serve(std::function<bool(Socket*)> handler);
  bool isVerbose() const;

  void connect();

  ssize_t read(char * buff, size_t len);
  ssize_t write(const char * buff, size_t len);

  char* read();
  void write(const char* str);

  uint64_t read_uint64();
  uint8_t read_uint8();

  void write_uint64(const uint64_t & value);
  void write_uint8(const uint8_t & value);

private:
  int sockfd;
  int connfd;
  uint16_t port;
  struct sockaddr_in * servaddr;
  std::string ip;
  bool verbose;
};