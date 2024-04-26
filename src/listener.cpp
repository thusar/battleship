#include <ctime>
#include "../include/listener.h"
#include "../include/socket.h"

void Listener::report(const std::string& msg, int terminate) {
  perror(msg.c_str());
  
  if (terminate) exit(-1); /* failure */
}

Listener::Listener(int listenerSocket, sockaddr_in sockaddr) 
    : _listenerSocket(listenerSocket)
    , _sockaddr(sockaddr)
{

}

std::string Listener::read()
{
//        socklen_t len = sizeof(_sockaddr);  /* address length could change */
//        _clientSocket = accept(_serverSocket, (sockaddr*)&_sockaddr, &len);  /* accept blocks */
//        if (_clientSocket < 0) {
//            report("accept error", 0); /* don't terminated, though there's a problem */
//        }
        char buffer[BUFFSIZE] = {0};
        ssize_t readReturn = recv(_listenerSocket, buffer, sizeof(buffer), 0);
        return std::string(buffer);
}

void Listener::write()
{
    std::string msg{""};
    std::srand(std::time(nullptr));
    std::uint8_t integerOne = std::rand() / ((RAND_MAX + 1u) / 2); // 1 or 2
    if (integerOne == 1)
        msg = std::string("x");
    else
        msg = std::string("o");  
    ssize_t writeReturn = ::write(_clientSocket, msg.data(), msg.size()); /* echo as confirmation */
}


