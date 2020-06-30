#include "Request/DeleteTaskArguments.h"

#include <iostream>

DeleteTaskArguments::DeleteTaskArguments(unsigned int taskId):
    mTaskId(taskId)
{
    std::cout << "Arguments for deleting of task was created" << std::endl;
}

DeleteTaskArguments::DeleteTaskArguments(Json::Value& jsonValue):
    mTaskId(jsonValue["task_id"].asUInt())
{
    std::cout << "Arguments for deleting of task was created" << std::endl;
}

DeleteTaskArguments::DeleteTaskArguments(Request& request):
    mTaskId(request.getArguments()["task_id"].asUInt())
{
    std::cout << "Arguments for deleting of task was created" << std::endl;
}

Json::Value DeleteTaskArguments::getJsonArguments()
{
    Json::Value jsonValue;
    jsonValue["task_id"] = mTaskId;
    return jsonValue;
}
