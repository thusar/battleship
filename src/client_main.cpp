#include <ctime>
#include "../include/client.h"
#include "../include/socket.h"

void wait(double sec)
{
    clock_t delay=sec;
    clock_t start=clock();
    while(clock()-start<delay);  
}

int main()
{
    // First client
    Client client{std::string("localhost"), PORTNUMBER};
    
    client.write(std::string("foo"));
    wait(SLEEPTIME);
    std::string msg = client.read();
    std::cout << "" << msg << std::endl;
    client.write(std::string("close connection"));

    // Second client
    Client clientSecond{std::string("localhost"), PORTNUMBER};
    clientSecond.write(std::string("foo"));
    wait(SLEEPTIME);
    msg = clientSecond.read();
    std::cout << "" << msg << std::endl;
    clientSecond.write(std::string("close connection"));
    
    return 0;
}