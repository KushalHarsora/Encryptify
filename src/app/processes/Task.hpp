#ifndef TASK_HPP
#define TASK_HPP

#include<string>
#include <iostream>
#include <sstream>
#include "../FileHandling/IO.hpp"

// Task like encrypt or decrypt
enum class Action {
    ENCRYPT,
    DECRYPT
};

struct Task {
    std::string filePath;
    std::fstream f_stream;
    Action action;

    // constructor to assign to local variables
    // directly assigning and not creating a variable but rather a volatile varible that will be destroyed after assigning
    Task(std::fstream &&stream, Action action, std::string filePath) : f_stream(std::move(stream)), action(action), filePath(filePath) {}

    std::string toString() {
        std::ostringstream oss;
        oss << filePath << "," << (action == Action::ENCRYPT? "ENCRYPT": "DECRYPT");
        // return string of file_path and action
        return oss.str();
    }

    static Task fromString(const std::string &taskData) {
        std::istringstream iss(taskData);
        std::string filePath;
        std::string actionString;

        if(std::getline(iss, filePath, ',') && std::getline(iss, actionString)) {
            Action action = (actionString == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT);
            IO io(filePath);
            // reading file
            std::fstream f_stream = std::move(io.getFileStream());
        
            if(f_stream.is_open()) {
                return Task(std::move(f_stream), action, filePath);
            } else {
                throw std::runtime_error("Failed to open the File: " + filePath);
            }
        } else {
            throw std::runtime_error("Invalid task data format");
        }
    }
};

#endif