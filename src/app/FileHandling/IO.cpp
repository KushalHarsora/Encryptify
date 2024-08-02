#include <iostream>
#include "io.hpp"

IO::IO(const std::string &file_path) {
    file_stream.open(file_path, std::ios::in | std::ios::out | std::ios::binary);
    if(!file_stream.is_open()) {
        std::cout << "Unable to open the file: " << file_path << std::endl;
    }
}

std::fstream IO::getFileStream() {
    return std::move(file_stream);
}