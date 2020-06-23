#include "ThreadPool.h"

ThreadPool::ThreadPool(unsigned int /* port */)
{
    // General concept:
    //
    // 1) Thread pool with 100 threads by default is used to process tasks
    // 2) New task is put to processing queue with @addTask method
    // 3) First available thread starts task processing

}

void ThreadPool::addTask(std::function<void ()> /* task */)
{
    // mutex with std::unique_lock should be used when access to queue of tasks is performed
    // conditionVariable.notify_one() should be used to notify any of threads when task is added
}

void ThreadPool::threadProcessor()
{
    // Can be used to extract function from queue and then process
    // How std::function works
    // https://en.cppreference.com/w/cpp/utility/functional/function
    std::function<void()> executor;

    // Note:
    // - Use mTerminate to check if process should be terminated
    // - Use std::mutex with std::unique_lock to control access to std::queue
    // - Use std::conditional_variable to check if the thread should be waked up
    while (true)
    {
        // Do something to execute function from queue
    }
}
