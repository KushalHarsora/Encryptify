#include <iostream>
#include "Cryption.hpp"

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr << "Usage: ./crytion <task_data>" << std::endl;
        return 1;
    }
    executeCryption(argv[1]);
    return 0;
}