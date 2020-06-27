#include "ThreadPool.h"

ThreadPool::ThreadPool(unsigned int numOfThreads)
{
    // General concept:
    //
    // 1) Thread pool with 100 threads by default is used to process tasks
    // 2) New task is put to processing queue with @addTask method
    // 3) First available thread starts task processing
    for (size_t i = 0; i < numOfThreads; i++) {
        workers.emplace_back([=] {threadProcessor();});
    }
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock{mutexForWorkers};
        mTerminate = true;
    }

    conditionForWorkers.notify_all();

    for(std::thread& thread : workers)
        thread.join();
}

void ThreadPool::addTask(std::function<void ()> task)
{
    // mutex with std::unique_lock should be used when access to queue of tasks is performed
    // conditionVariable.notify_one() should be used to notify any of threads when task is added
    {
        std::unique_lock<std::mutex> lock{mutexForWorkers};
        tasks.emplace(std::move(task));
    }

    conditionForWorkers.notify_one();
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
        {
            std::unique_lock<std::mutex> lock{mutexForWorkers};

            conditionForWorkers.wait(lock, [=] {return mTerminate || !tasks.empty();});

            if(mTerminate && tasks.empty()){
                break;
            }
            executor = std::move(tasks.front());
            tasks.pop();
        }

        executor();
    }
}
