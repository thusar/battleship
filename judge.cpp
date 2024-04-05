
#include "socket.h"
#include "config.h"
#include <string.h>
#include <iostream>

bool handler(Socket * sock)
{
  char buff[BUFFER_SIZE];
  bool connected = true;
  bool keep_listening = true;
  while(connected)
  {
    bzero(buff, BUFFER_SIZE);
    sock->read(buff, sizeof(buff));
    buff[BUFFER_SIZE-1] = 0;
    std::cout << "from client " << buff << std::endl;
    if (strcmp("exit", buff) == 0)
    {
      if(sock->isVerbose())
      {
        std::cout << "exit" << std::endl;
      }
      connected = false;
      keep_listening = false;
      sock->write("disconnect", strlen("disconnect") + 1);
    }
    else if (strcmp("disconnect", buff) == 0)
    {
      connected = false;
      keep_listening = true;
      sock->write("disconnect", strlen("disconnect") + 1);
      if(sock->isVerbose())
      {
        std::cout << "disconnect" << std::endl;
      }

    }
    else
    {
      printf(">");
      bzero(buff, BUFFER_SIZE);
      for(int i =0; i < BUFFER_SIZE-1; i++)
      {
        char ch = getchar();
        if(ch != '\n')
        {
          buff[i] = ch;
        }
        else
        {
          break;
        }
      }
      sock->write(buff, sizeof(buff));
    }
  }
  return keep_listening;
}

int main(int argc, const char ** argv)
{
  int port = 8080;
  std::string ipaddr = "0.0.0.0";
  bool printHelp = false;
  bool argError = false;
  bool verbose = false;
  for(int i = 0; i < argc; ++i)
  {
    std::string arg(argv[i]);
    if(arg == "--port" || arg == "-p")
    {
      ++i;
      if(i < argc)
      {
        try
        {
          port = stoi(std::string(argv[i]));
        }
        catch(std::exception ex)
        {
          std::cerr << "invalid port number " << argv[i] << std::endl;
          argError = true;
        }
      }
      else
      {
        std::cerr << "missing argument " << argv[i] << " PORT" << std::endl;
        argError = true;
      }
    }
    if(arg == "--addr" || arg == "-a")
    {
      ++i;
      if(i < argc)
      {
        ipaddr = argv[i];
      }
      else
      {
        std::cerr << "missing argument " << argv[i] << " IPv4" << std::endl;
        argError = true;
      }
    }
    if(arg == "--help" || arg == "-h")
    {
      printHelp = true;
    }
    if(arg == "--verbose" || arg == "-v")
    {
      verbose = true;
    }
  }
  if(printHelp || argError)
  {
    std::cout << argv[0] << "[OPTIONS]" << std::endl;
    std::cout << "OPTIONS:" << std::endl;
    std::cout << "--port|-p PORT" << std::endl;
    std::cout << "--addr|-a IPv4" << std::endl;
    std::cout << "--verbose|-v" << std::endl;
    std::cout << "--help|-h" << std::endl;
    if(argError)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  try
  {
    Socket sock(ipaddr, port, verbose);
    sock.serve(handler);
  }
  catch(const std::exception & ex)
  {
    std::cerr << "server failed:" << ex.what() << std::endl;
    return 8;
  }
  return 0;
}