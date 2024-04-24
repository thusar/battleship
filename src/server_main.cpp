#include "../include/server.h"
#include "../include/socket.h"

int main()
{
    Server server;
    std::string msg = server.read();
    std::cout << "server main message: " << msg << std::endl;
    server.write();
    return 0;
}