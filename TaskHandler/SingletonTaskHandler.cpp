#include "TaskHandler/SingletonTaskHandler.h"

SingletonTaskHandler* SingletonTaskHandler::pInstance = nullptr;

SingletonTaskHandler::SingletonTaskHandler()
{
    mapTasks = new std::map<const unsigned int, Task>;
}

SingletonTaskHandler::~SingletonTaskHandler()
{
    delete mapTasks;
}

SingletonTaskHandler* SingletonTaskHandler::getInstance()
{
    if(!pInstance)
        pInstance = new SingletonTaskHandler();
    return pInstance;
}

void SingletonTaskHandler::deleteInstance()
{
    delete pInstance;
}

std::vector<Task> SingletonTaskHandler::getTasks() const
{
    std::vector<Task> vectorTasks;
    vectorTasks.resize(mapTasks->size());
    std::transform(mapTasks->begin(), mapTasks->end(),
                   vectorTasks.begin(), [] (std::pair<const unsigned int, Task>& pair) -> Task
    {
        return pair.second;
    });
    return vectorTasks;
}

bool SingletonTaskHandler::addTask(const Task& task)
{
    if(mapTasks->find(task.getTaskId()) != mapTasks->end())
        return false;

    mapTasks->insert(std::pair<const unsigned int, Task>(task.getTaskId(), task));
    return true;
}

void SingletonTaskHandler::deleteTaskById(unsigned int id)
{
    auto searchResult = mapTasks->find(id);
    if(searchResult != mapTasks->end())
        mapTasks->erase(searchResult);
}

bool SingletonTaskHandler::updateTask(const Task& task)
{
    auto searchResult = mapTasks->find(task.getTaskId());
    if(searchResult == mapTasks->end())
        return false;
    else
        mapTasks->erase(searchResult);

    addTask(task);
    return true;
}

void SingletonTaskHandler::clearTasks()
{
    mapTasks->clear();
}
