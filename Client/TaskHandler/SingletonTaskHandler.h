#ifndef SINGLETONTASKHANDLER_H
#define SINGLETONTASKHANDLER_H

#include "Task/Task.h"
#include <algorithm>
#include <map>

/**
 * @brief Provides single access to task list in the program
 */
// Task: implement SingletonTaskHandler
//
// Read about Singleton pattern
// http://cpp-reference.ru/patterns/creational-patterns/singleton/
//
// Implement needed API
//
// Singleton will be used in a way:
// SingletonTaskHandler::getInstance()->addTask(task)
class SingletonTaskHandler
{
public:
    /**
     * @return instance of SingletonTaskHandler
     */
    static SingletonTaskHandler* getInstance();

    /**
     * @brief Deletes instance of SingletonTaskHandler
     *        Usually used at the end of program execution
     */
    static void deleteInstance();

    /**
     * @brief Adds task with provided ID to list of tasks
     * @param task Task to be added
     * @return true if task was added, false if task with such ID already exist
     */
    bool addTask(const Task& task);

    /**
     * @brief Updates task with provided ID in list of tasks
     * @param task Task to be updated
     * @return true if task is exist and updated, false otherwise
     */
    bool updateTask(const Task& task);

    /**
     * @brief Deletes task with provided ID from list of tasks
     * @param id Id of task to be deleted
     */
    void deleteTaskById(unsigned int id);

    /**
     * @brief clears vector of tasks
     */
    void clearTasks();

    /**
     * @return vector of tasks
     */
    std::vector<Task> getTasks() const;

private:
    static SingletonTaskHandler* pInstance;
    std::map<const unsigned int, Task>* mapTasks;
    SingletonTaskHandler();
    ~SingletonTaskHandler();
};

#endif // SINGLETONTASKHANDLER_H
