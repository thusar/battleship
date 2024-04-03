
#include <cstdlib>
#include <functional>
#include <iostream>

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
        int returnValue = std::system("socket -sl 3425");
    }
    
}