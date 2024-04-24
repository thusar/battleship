
#include "../include/client.h"
#include "../include/socket.h"

int main()
{
    Client client;
    
    client.write();
    std::string msg = client.read();
    std::cout << "client main message: " << msg << std::endl;
    return 0;
}