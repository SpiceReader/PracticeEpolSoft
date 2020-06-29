#include "Request/UpdateTaskArguments.h"

#include <iostream>

UpdateTaskArguments::UpdateTaskArguments(unsigned int taskId, std::string taskName,
                                         std::string taskDescription, Task::Status status):
    mTaskId(taskId),
    mTaskName(taskName),
    mTaskDescription(taskDescription),
    mTaskStatus(status)
{
    std::cout << "Arguments for creation of task was created" << std::endl;
}

UpdateTaskArguments::UpdateTaskArguments(unsigned int taskId, Task &task):
    mTaskId(taskId),
    mTaskName(task.getTaskName()),
    mTaskDescription(task.getTaskDescription()),
    mTaskStatus(task.getTaskStatus())
{
    std::cout << "Arguments for creation of task was created" << std::endl;
}

Json::Value UpdateTaskArguments::getJsonArguments()
{
    Json::Value jsonValue;
    jsonValue["task_id"] = mTaskId;
    jsonValue["task_name"] = mTaskName;
    jsonValue["task_description"] = mTaskDescription;
    jsonValue["status"] = mTaskStatus;
    return jsonValue;
}
