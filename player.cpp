#include "socket.h"
#include "config.h"
#include <iostream>
#include <mutex>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <thread>
#include "console.h"

std::mutex lock;

void conversation(const std::string ipaddr,
                  int port,
                  bool verbose)
{

    std::lock_guard<decltype(lock)> latch(lock);
    // Player 1 or Player 2 access console
    ConsoleCreationParameters ccp{10, 14, 10, 10, false, true};
    Console console{ccp};

  Socket sock(ipaddr, port, verbose);
  sock.connect();
  char buff[BUFFER_SIZE];
  int n;
  bool connected = true;
  while(connected)
  {
    bzero(buff, sizeof(buff));
    std::cout << ">";
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
    sock.write(buff, sizeof(buff));
    bzero(buff, sizeof(buff));
    sock.read(buff, sizeof(buff));
    buff[BUFFER_SIZE-1] = 0;
    std::cout << "from server:" << buff << std::endl;
    if(strcmp("disconnect", buff) == 0)
    {
      connected = false;
    }
  }
}



int main(int argc, const char ** argv) {
  int port = 8080;
  std::string ipaddr = "127.0.0.1";
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
    constexpr int numberOfThreads = 2;
    std::vector<std::thread> playerThreads;
    for (int i = 1; i < numberOfThreads; ++i) {
        playerThreads.push_back(std::thread(conversation, ipaddr, port, verbose));
    }
    // access to console from main thread
    conversation(ipaddr, port, verbose);
    for (auto& playerThread: playerThreads) {
        playerThread.join();
        // access to console from additional thread
    }

    
  }
  catch(const std::exception & ex)
  {
    std::cerr << "conversation failed:" << ex.what() << std::endl;
    return 8;
  }

  return 0;
}