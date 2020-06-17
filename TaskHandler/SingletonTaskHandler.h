#ifndef SINGLETONTASKHANDLER_H
#define SINGLETONTASKHANDLER_H

#include "Task.h"

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
    //static SingletonTaskHandler* getInstance();
    /**
     * @brief Deletes instance of SingletonTaskHandler
     *        Usually used at the end of program execution
     */
    //static void deleteInstance();

    /**
     * @brief Adds task with provided ID to list of tasks
     * @param task Task to be added
     * @return true if task was added, false if task with such ID already exist
     */
    //bool addTask(const Task& task);

    /**
     * @brief Updates task with provided ID in list of tasks
     * @param task Task to be updated
     * @return true if task is exist and updated, false otherwise
     */
    //bool updateTask(const Task& task);

    /**
     * @brief clears vector of tasks
     */
    //void clearTasks();

    /**
     * @return vector of tasks
     */
    //std::vector<Task> getTasks() const;

private:
    SingletonTaskHandler();
};

#endif // SINGLETONTASKHANDLER_H
