#include "../include/listener.h"
#include "../include/server.h"
#include "../include/socket.h"
 

int main()
{
    std::string msg{""};
    Listener listener(HOST, PORTNUMBER);

    bool running{true};
    Server server(listener.get_listener_socket());
    while (running) {
        sockaddr_in socketAddr = listener.accept();
        msg = socketAddr.recv();
        std::cout << msg << std::endl;
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