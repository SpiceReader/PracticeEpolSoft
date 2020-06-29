#include "Request/CreateTaskArguments.h"

#include <iostream>

CreateTaskArguments::CreateTaskArguments(std::string taskName, std::string taskDescription, Task::Status status):
    mTaskName(taskName),
    mTaskDescription(taskDescription),
    mTaskStatus(status)
{
    std::cout << "Arguments for creation of task was created" << std::endl;
}

CreateTaskArguments::CreateTaskArguments(Task& task):
    mTaskName(task.getTaskName()),
    mTaskDescription(task.getTaskDescription()),
    mTaskStatus(task.getTaskStatus())
{

}

Json::Value CreateTaskArguments::getJsonArguments()
{
    Json::Value jsonValue;
    jsonValue["task_name"] = mTaskName;
    jsonValue["task_description"] = mTaskDescription;
    jsonValue["status"] = mTaskStatus;
    return jsonValue;
}
