#include <iostream>
#include <mutex>
#include <string>
#include <thread>

#include "board.h"
#include "socket.h"

std::mutex lock;

// void conversation(const std::string ipaddr,
//                   int port,
//                   bool verbose)
// {

//     std::lock_guard<decltype(lock)> latch(lock);
//     // Player 1 or Player 2 access console
//     ConsoleCreationParameters ccp{10, 14, 10, 10, false, true};
//     Console console{ccp};

//   Socket sock(ipaddr, port, verbose);
//   sock.connect();
//   char buff[BUFFER_SIZE];
//   int n;
//   bool connected = true;
//   while(connected)
//   {
//     bzero(buff, sizeof(buff));
//     std::cout << ">";
//     for(int i =0; i < BUFFER_SIZE-1; i++)
//     {
//       char ch = getchar();
//       if(ch != '\n')
//       {
//         buff[i] = ch;
//       }
//       else
//       {
//         break;
//       }
//     }
//     sock.write(buff, sizeof(buff));
//     bzero(buff, sizeof(buff));
//     sock.read(buff, sizeof(buff));
//     buff[BUFFER_SIZE-1] = 0;
//     std::cout << "from server:" << buff << std::endl;
//     if(strcmp("disconnect", buff) == 0)
//     {
//       connected = false;
//     }
//   }
// }



int main(int argc, char* argv[]) 
{
    constexpr int port {8080};
    const std::string localhost {"127.0.0.1"};

    return 0;
}

//   try
//   {
//     constexpr int numberOfThreads = 2;
//     std::vector<std::thread> playerThreads;
//     for (int i = 1; i < numberOfThreads; ++i) {
//         playerThreads.push_back(std::thread(conversation, ipaddr, port, verbose));
//     }
//     // access to console from main thread
//     conversation(ipaddr, port, verbose);
//     for (auto& playerThread: playerThreads) {
//         playerThread.join();
//         // access to console from additional thread
//     }

    
