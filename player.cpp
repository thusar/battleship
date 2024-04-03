#include <cstdlib>
#include <iostream>

int main() {
    const char* saddr = "127.0.0.1";
    int sockfd;
    int returnValue = std::system("connect(sockfd, (struct sockaddr *) &saddr, sizeof(saddr))");
    return 0;
}