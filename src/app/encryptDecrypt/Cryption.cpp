#include "Cryption.hpp"
#include "../processes/Task.hpp"
#include "../FileHandling/ReadENV.cpp"

int executeCryption(const std::string &taskdata) {
    Task task = Task::fromString(taskdata);
    ReadENV env;

    std::string envKey = env.get_env();
    int key = std::stoi(envKey);

    if(task.action == Action::ENCRYPT) {
        char ch;

        // Substitution Cipher
        while (task.f_stream.get(ch)) {
            ch = (ch+key) % 256;
            task.f_stream.seekp(-1, std::ios::cur);
            task.f_stream.put(ch);
        }
        task.f_stream.close();
    } else {
        char ch;
        
        // Decrypt Cipher Text
        while(task.f_stream.get(ch)) {
            ch = (ch-key+256) % 256;
            task.f_stream.seekp(-1, std::ios::cur);
            task.f_stream.put(ch);
        }
        task.f_stream.close();
    }

    return 0;
}