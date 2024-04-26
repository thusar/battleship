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
    Listener listener(HOST, PORTNUMBER);
    // Server server{listener};
    bool running{true};
    while (running) {
        int clientFileDescriptor = listener.accept();
        // char buffer[BUFFSIZE] = {0};
        // ssize_t readReturn = listener.read();

        msg = clientFileDescriptor.recv();
        std::cout << msg << std::endl;
        // listener.write();
        if (msg == std::string("close connection")) {
            break;
        }
        if (msg == std::string("close server")) {
            running = false;
            break;
        }
    };
    return 0;
}