#include"ProcessManagement.hpp"
#include <iostream>
#include <cstring>
#ifdef _WIN32
// Windows-specific includes
#include <windows.h>
#else
// Unix-specific includes
#include <sys/wait.h>
#endif


ProcessManagement::ProcessManagement() {}

bool ProcessManagement::submitToQueue(std::unique_ptr<Task> task) {
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTasks() {
    while(!taskQueue.empty()) {
        // brings the first element from queue for execution
        std::unique_ptr<Task> taskToExecute = std::move(taskQueue.front());
        // Once ownership is transfered then pop from queue
        taskQueue.pop();
        std::cout << "Executing task: " << taskToExecute->toString() << std::endl;
        // takes serialized string and then de-serializes it
        executeCryption(taskToExecute->toString());
    }
}