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
    static SingletonTaskHandler* getInstance();
    static void deleteInstance();
    bool addTask(const Task& task);
    bool updateTask(const Task& task);
    void deleteTaskById(unsigned int id);
    void clearTasks();
    std::vector<Task> getTasks() const;

private:
    static SingletonTaskHandler* pInstance;
    std::map<const unsigned int, Task>* mapTasks;
    SingletonTaskHandler();
    ~SingletonTaskHandler();
};

#endif // SINGLETONTASKHANDLER_H
