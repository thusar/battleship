#include "../include/listener.h"
#include "../include/server.h"
#include "../include/socket.h"
 

int main()
{
//    Server server;
//    std::string msg = server.read();
//    std::cout << "server main message: " << msg << std::endl;
//    server.write();
//    return 0;
    std::string msg{""};
    sockaddr_in sockaddrListener{};
    sockaddrListener.sin_family = AF_INET;                /* versus AF_LOCAL */
    sockaddrListener.sin_addr.s_addr = htonl(INADDR_ANY); /* host-to-network endian */
    sockaddrListener.sin_port = htons(PORTNUMBER);        /* for listening */
    Listener listener(HOST, sockaddrListener);
    Server server{listener};
    bool running{true};
    while (running) {
        char buffer[BUFFSIZE] = {0};
        ssize_t readReturn = recv(server._clientSocket, buffer, sizeof(buffer), 0);
        msg = listener.read();
        std::cout << msg << std::endl;
        listener.write();
        if (msg == std::string("close connection")) {
            break;
        }
        if (msg == std::string("close server")) {
            running = False
            break;
        }
    };
    return 0;
}