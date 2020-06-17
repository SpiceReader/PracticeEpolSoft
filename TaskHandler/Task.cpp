// std
#include <iostream>

// internal
#include "Task.h"

Task::Task()
{
    std::cout << "Creates empty task" << std::endl;
}

unsigned int Task::getTaskId() const
{
    return mTaskId;
}

void Task::setTaskId(unsigned int taskId)
{
    mTaskId = taskId;
}

const std::string Task::getTaskName() const
{
    return mTaskName;
}

void Task::setTaskName(const std::string& taskName)
{
    mTaskName = taskName;
}

void Task::addComment(const std::string& /* comment */)
{
    // TODO: implement addComment method
}

std::vector<std::string> Task::getComments()
{
    // TODO: implement getComments method
    // Note: Empty vector is here only to disable compilation error, please remove it before implementation
    return std::vector<std::string>();
}
