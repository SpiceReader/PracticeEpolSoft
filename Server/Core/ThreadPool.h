#ifndef SERVER_H
#define SERVER_H

// std
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

/**
 * Thread pool for server
 */
class ThreadPool
{
public:
    /**
     * Constructs Thread Pool
     * @param numOfThreads Numbr of threads in thread pool
     */
    ThreadPool(unsigned int numOfThreads = 100);

    /**
     * Adds task to queue
     * @param task Task to be added
     */
    void addTask(std::function<void()> task);

private:

    /**
     * Used by each thread in thread pool to extract task from queue and process it
     */
    void threadProcessor();

    /**
     * Vector of threads used to process incoming requests
     */
    std::vector<std::thread> workers;

    /**
     * Queue of tasks for processing, each task is function without params
     * (usually - lambda-expression)
     */
    std::queue<std::function<void()>> tasks;

    /**
     * Mutex to control access to functional queue
     */
    std::mutex mutexForWorkers;

    /**
     * Used to block threads while no tasks available and unlock thread by signal outside
     */
    std::condition_variable conditionForWorkers;

    /**
     * Used to terminate threads when application is terminated
     */
    bool mTerminate;
};

#endif // SERVER_H
