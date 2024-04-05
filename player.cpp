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
#include <unistd.h>
#include "console.h"

std::mutex lock;

void AccessToConsole()
{
    std::lock_guard<decltype(lock)> latch(lock);
    // Player 1 or Player 2 access console
    ConsoleCreationParameters ccp{10, 14, 10, 10, false, true};
    Console console{ccp};
}

int main(int argc, char const* argv[]) {
    const int PORT{8080};
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    const char* hello = "Hello from client";
    char buffer[1024] = { 0 };
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
 
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }
 
    if ((status
         = connect(client_fd, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(client_fd, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    valread = read(client_fd, buffer,
                   1024 - 1); // subtract 1 for the null
                              // terminator at the end
    printf("%s\n", buffer);
 
    // closing the connected socket
    close(client_fd);

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