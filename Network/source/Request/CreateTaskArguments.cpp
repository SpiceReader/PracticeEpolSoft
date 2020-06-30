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
    std::cout << "Arguments for creation of task was created" << std::endl;
}

CreateTaskArguments::CreateTaskArguments(Json::Value& jsonValue):
    mTaskName(jsonValue["task_name"].asString()),
    mTaskDescription(jsonValue["task_description"].asString()),
    mTaskStatus(static_cast<Task::Status>(jsonValue["status"].asInt()))
{
    std::cout << "Arguments for creation of task was created" << std::endl;
}

CreateTaskArguments::CreateTaskArguments(Request& request)
{
    Json::Value argumentsList {request.getArguments()};

    mTaskName = argumentsList["task_name"].asString();
    mTaskDescription = argumentsList["task_description"].asString();
    mTaskStatus = static_cast<Task::Status>(argumentsList["status"].asInt());

    std::cout << "Arguments for creation of task was created" << std::endl;
}

Json::Value CreateTaskArguments::getJsonArguments()
{
    Json::Value jsonValue;
    jsonValue["task_name"] = mTaskName;
    jsonValue["task_description"] = mTaskDescription;
    jsonValue["status"] = mTaskStatus;
    return jsonValue;
}
