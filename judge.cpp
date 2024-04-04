
#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 2) {
        std::cout << argv[0] << std::endl;
        std::cout << "Usage: " << argv[0] << " 2" << std::endl;
        return 1;        
    } else if (argc == 2 && argv[1] != std::string("2")){
        std::cout << argv[0] << std::endl;
        std::cout << "Usage: " << argv[0] << " 2" << std::endl;
        return 1;
    } else {
        struct sockaddr_in saddr, caddr;
        int sockfd, isock;
        unsigned short port = 1938;
        if((sockfd=socket(AF_INET, SOCK_STREAM, 0) < 0)) { // from back a couple slides
            std::cout << std::string("Error creating socket") << std::endl;
        }
        memset(&saddr, '\0', sizeof(saddr)); // zero structure out
        saddr.sin_family = AF_INET; // match the socket() call
        saddr.sin_addr.s_addr = htonl(INADDR_ANY); // bind to any local address
        saddr.sin_port = htons(1938); // specify port to listen on
        if((bind(sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0)) { // bind!
            std::cout << "Error binding\n";
        }
        if(listen(sockfd, 2) < 0) { // listen for incoming connections
            std::cout << "Error listening\n";
        }
        unsigned int clen=sizeof(caddr);
        if((isock=accept(sockfd, (struct sockaddr *) &caddr, &clen)) < 0) { // accept one
            std::cout << "Error accepting\n";
        }
    }
    return 0;
    
}