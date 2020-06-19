#include "TaskHandler/SingletonTaskHandler.h"

SingletonTaskHandler* SingletonTaskHandler::pInstance = nullptr;

SingletonTaskHandler::SingletonTaskHandler()
{
    vectorTasks = new std::vector<Task>;
}

SingletonTaskHandler::~SingletonTaskHandler()
{
    delete vectorTasks;
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
    return std::vector<Task>(*vectorTasks);
}

bool SingletonTaskHandler::addTask(const Task& task)
{
    for(Task& iterTask : *vectorTasks){
        if(iterTask.getTaskId() == task.getTaskId()){
            return false;
        }
    }
    vectorTasks->push_back(task);
    return true;
}

void SingletonTaskHandler::deleteTaskById(unsigned int id)
{
    for(auto taskIter = vectorTasks->begin(); taskIter < vectorTasks->end(); taskIter++){
        if(taskIter->getTaskId() == id){
            vectorTasks->erase(taskIter);
            break;
        }
    }
}

bool SingletonTaskHandler::updateTask(const Task& task)
{
    deleteTaskById(task.getTaskId());
    addTask(task);
    return false;
}

void SingletonTaskHandler::clearTasks()
{
    vectorTasks->clear();
}
