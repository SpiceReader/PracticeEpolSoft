#include "Request/UpdateTaskArguments.h"

#include <iostream>

UpdateTaskArguments::UpdateTaskArguments(unsigned int taskId, std::string taskName,
                                         std::string taskDescription, Task::Status status):
    mTaskId(taskId),
    mTaskName(taskName),
    mTaskDescription(taskDescription),
    mTaskStatus(status)
{
    mValid = (!mTaskName.size() || !(mTaskStatus >= 1 && mTaskStatus <= 4)) ? false : true;
    std::cout << "Arguments for creation of task was created" << std::endl;
}

UpdateTaskArguments::UpdateTaskArguments(unsigned int taskId, Task &task):
    mTaskId(taskId),
    mTaskName(task.getTaskName()),
    mTaskDescription(task.getTaskDescription()),
    mTaskStatus(task.getTaskStatus())
{
    mValid = (!mTaskName.size() || !(mTaskStatus >= 1 && mTaskStatus <= 4)) ? false : true;
    std::cout << "Arguments for updating of task was created" << std::endl;
}

UpdateTaskArguments::UpdateTaskArguments(Json::Value &jsonValue)
{
    if(!jsonValue["task_id"].isNull() && jsonValue["task_id"].isUInt())
        mTaskId = jsonValue["task_id"].asUInt();
    else{
        mTaskId = 0;
        mValid = false;
    }

    if(!jsonValue["task_name"].isNull() && jsonValue["task_name"].isString())
        mTaskName = jsonValue["task_name"].asString();
    else{
        mTaskName = "";
        mValid = false;
    }

    if(!jsonValue["task_description"].isNull() && jsonValue["task_description"].isString())
        mTaskDescription = jsonValue["task_description"].asString();
    else{
        mTaskDescription = "";
        mValid = false;
    }

    if(!jsonValue["status"].isNull() && jsonValue["status"].isInt())
        mTaskStatus = static_cast<Task::Status>(jsonValue["status"].asInt());
    else{
        mTaskStatus = static_cast<Task::Status>(0);
        mValid = false;
    }

    if(!mTaskName.size() || !(mTaskStatus >= 1 && mTaskStatus <= 4))
        mValid = false;

    std::cout << "Arguments for updating of task was created" << std::endl;
}

UpdateTaskArguments::UpdateTaskArguments(Request &request)
{
    Json::Value argumentsList {request.getArguments()};

    if(argumentsList.isNull()){
        mTaskId = 0;
        mTaskName = "";
        mTaskDescription = "";
        mTaskStatus = static_cast<Task::Status>(0);
        mValid = false;
        return;
    }

    if(!argumentsList["task_id"].isNull() && argumentsList["task_id"].isUInt())
        mTaskId = argumentsList["task_id"].asUInt();
    else{
        mTaskId = 0;
        mValid = false;
    }

    if(!argumentsList["task_name"].isNull() && argumentsList["task_name"].isString())
        mTaskName = argumentsList["task_name"].asString();
    else{
        mTaskName = "";
        mValid = false;
    }

    if(!argumentsList["task_description"].isNull() && argumentsList["task_description"].isString())
        mTaskDescription = argumentsList["task_description"].asString();
    else{
        mTaskDescription = "";
        mValid = false;
    }

    if(!argumentsList["status"].isNull() && argumentsList["status"].isInt())
        mTaskStatus = static_cast<Task::Status>(argumentsList["status"].asInt());
    else{
        mTaskStatus = static_cast<Task::Status>(0);
        mValid = false;
    }

    if(!mTaskName.size() || !(mTaskStatus >= 1 && mTaskStatus <= 4))
        mValid = false;

    std::cout << "Arguments for updating of task was created" << std::endl;
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
