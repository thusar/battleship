#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <mutex>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <thread>

#include "console.h"

std::mutex lock;

void AccessToConsole()
{
    std::lock_guard<decltype(lock)> latch(lock);
    // Player 1 or Player 2 access console
    ConsoleCreationParameters ccp{10, 14, 10, 10, false, true};
    Console console{ccp};
}

int main() {
    struct sockaddr_in saddr;
    struct hostent *h;
    int sockfd, connfd;
    unsigned short port = 1236;
    if((sockfd=socket(AF_INET, SOCK_STREAM, 0) < 0)) { // from back a couple slides
        std::cout << "Error creating socket\n";
    }
    const char* ipstr = "127.0.0.1";
    struct in_addr ip;
    if((h=gethostbyaddr((const void *)&ip, sizeof(ip), AF_INET)) == nullptr) { // Lookup the hostname
        std::cout << "Unknown host\n";
    }
    memset(&saddr, '\0', sizeof(saddr)); // zero structure out
    saddr.sin_family = AF_INET; // match the socket() call
    memcpy((char *) &saddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length); // copy the address
    saddr.sin_port = htons(port); // specify port to connect to
    if((connfd=connect(sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0)) { // connect!
        std::cout << "Cannot connect\n";
    }

    constexpr int numberOfThreads = 2;
    std::vector<std::thread> playerThreads;
    for (int i = 1; i < numberOfThreads; ++i) {
        playerThreads.push_back(std::thread(AccessToConsole));
    }
    // access to console from main thread
    AccessToConsole();
    for (auto& playerThread: playerThreads) {
        playerThread.join();
        // access to console from additional thread
    }
}