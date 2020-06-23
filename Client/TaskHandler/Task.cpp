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

void Task::addComment(const std::string& comment)
{
    // TODO: implement addComment method
    if (comment.length() != 0) {
        mComments.push_back(comment);
    }
}

void Task::setTaskDescription (const std::string &description)
{
    mTaskDescription = description;
}

const std::string Task::getTaskDescription () const
{
    return mTaskDescription;
}

void Task::setTaskStatus(Status stat)
{
    this->mTaskStatus = stat;
}

Task::Status Task::getTaskStatus() const
{
    return mTaskStatus;
}

const std::vector<std::string> Task::getComments() const
{
    // TODO: implement getComments method
    // Note: Empty vector is here only to disable compilation error, please remove it before implementation
    return this->mComments;
}
