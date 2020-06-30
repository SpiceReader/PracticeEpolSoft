#include "Request/CreateTaskArguments.h"

#include <iostream>

CreateTaskArguments::CreateTaskArguments(std::string taskName, std::string taskDescription, Task::Status status):
    mTaskName(taskName),
    mTaskDescription(taskDescription),
    mTaskStatus(status)
{
    mValid = (!mTaskName.size() || !(mTaskStatus >= 1 && mTaskStatus <= 4)) ? false : true;
    std::cout << "Arguments for creation of task was created" << std::endl;
}

CreateTaskArguments::CreateTaskArguments(Task& task):
    mTaskName(task.getTaskName()),
    mTaskDescription(task.getTaskDescription()),
    mTaskStatus(task.getTaskStatus())
{
    mValid = (!mTaskName.size() || !(mTaskStatus >= 1 && mTaskStatus <= 4)) ? false : true;
    std::cout << "Arguments for creation of task was created" << std::endl;
}

CreateTaskArguments::CreateTaskArguments(Json::Value& jsonValue)
{
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
        mTaskStatus = Task::OPEN;
        mValid = false;
    }

    if(!mTaskName.size() || !(mTaskStatus >= 1 && mTaskStatus <= 4))
        mValid = false;

    std::cout << "Arguments for creation of task was created" << std::endl;
}

CreateTaskArguments::CreateTaskArguments(Request& request)
{
    Json::Value argumentsList {request.getArguments()};

    if(argumentsList.isNull()){
        mTaskName = "";
        mTaskDescription = "";
        mTaskStatus = Task::OPEN;
        mValid = false;
        return;
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
        mTaskStatus = Task::OPEN;
        mValid = false;
    }

    if(!mTaskName.size() || !(mTaskStatus >= 1 && mTaskStatus <= 4))
        mValid = false;

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
