#include "Request/DeleteTaskArguments.h"

#include <iostream>

DeleteTaskArguments::DeleteTaskArguments(unsigned int taskId):
    mTaskId(taskId)
{
    std::cout << "Arguments for deleting of task was created" << std::endl;
}

Json::Value DeleteTaskArguments::getJsonArguments()
{
    Json::Value jsonValue;
    jsonValue["task_id"] = mTaskId;
    return jsonValue;
}
