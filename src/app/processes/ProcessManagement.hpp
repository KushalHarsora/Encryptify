#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "Task.hpp"
#include <queue>
#include <memory>

class ProcessManagement {

    public:
        ProcessManagement();
        bool submitToQueue(std::unique_ptr<Task> task);
        void executeTasks();

    private:
        // unique_ptr -> frees unused pts and avoids memory leak, only one ptr can have reference addr and if you want another ptr to have same addr then use "move" to transfer ownership. Avoids double assignment to same addr.
        // unique_ptr -> <very_important> -> similar to java garbage collector

        // here using unique_ptr to avoid unauth access to tasks in queue
        std::queue<std::unique_ptr<Task>> taskQueue;
};


#endif