#include "../include/server.h"
#include "../include/socket.h"

int main()
{
    Server server;
    std::string msg = server.read();
    server.write(msg);
    return 0;
}