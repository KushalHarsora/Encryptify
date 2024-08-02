#include <iostream>
#include <fstream>
#include <string>
#include "IO.hpp"
#include <sstream>

class ReadENV {
    public:
        // reading env
        std::string get_env() {
            // get path
            std::string env_path = ".env";
            // send path to IO to open it
            IO io(env_path);
            // get file stream for env
            std::fstream f_stream = io.getFileStream();
            std::stringstream buffer;
            // store into buffer
            buffer << f_stream.rdbuf();
            // convert buffer to string
            std::string content = buffer.str();
            return content;
        }
};