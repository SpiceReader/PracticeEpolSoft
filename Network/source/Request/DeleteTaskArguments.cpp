#include "Request/DeleteTaskArguments.h"

#include <iostream>

DeleteTaskArguments::DeleteTaskArguments(unsigned int taskId):
    mTaskId(taskId)
{
    std::cout << "Arguments for deleting of task was created" << std::endl;
}

DeleteTaskArguments::DeleteTaskArguments(Json::Value& jsonValue)
{
    if(!jsonValue["task_id"].isNull() && jsonValue["task_id"].isUInt())
        mTaskId = jsonValue["task_id"].asUInt();
    else{
        mTaskId = 0;
        mValid = false;
    }

    std::cout << "Arguments for deleting of task was created" << std::endl;
}

DeleteTaskArguments::DeleteTaskArguments(Request& request)
{
    Json::Value argumentsList {request.getArguments()};

    if(argumentsList.isNull()){
        mTaskId = 0;
        mValid = false;
        return;
    }

    if(!argumentsList["task_id"].isNull() && argumentsList["task_id"].isUInt())
        mTaskId = argumentsList["task_id"].asUInt();
    else{
        mTaskId = 0;
        mValid = false;
    }

    std::cout << "Arguments for deleting of task was created" << std::endl;
}

Json::Value DeleteTaskArguments::getJsonArguments()
{
    Json::Value jsonValue;
    jsonValue["task_id"] = mTaskId;
    return jsonValue;
}
