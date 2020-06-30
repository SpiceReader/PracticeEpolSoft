#ifndef CREATETASKARGUMENTS_H
#define CREATETASKARGUMENTS_H

#include <string>
#include <Task/Task.h>
#include <json/json.h>
#include "Request.h"

class CreateTaskArguments
{
public:
    /**
     * @brief Creates arguments which needed to be used in request
     * @param taskName Name of created task
     * @param taskDescription Desciption of created task
     * @param status Status of created task
     */
    CreateTaskArguments(std::string taskName, std::string taskDescription, Task::Status status);

    /**
     * @brief Creates arguments from task in memory
     * @param task Object of Task class
     */
    CreateTaskArguments(Task& task);

    /**
     * @brief Creates arguments from JSON
     * @param jsonValue Object of JSON with fields to create Task
     */
    CreateTaskArguments(Json::Value& jsonValue);

    /**
     * @brief Creates arguments from Request
     * @param request JSON object with fields CommandCode and Arguments
     */
    CreateTaskArguments(Request& request);

    /**
     * @brief Convert all arguments to json object
     * @return Json object with fields, needed to create task
     */
    Json::Value getJsonArguments();

    /**
     * @brief Check if json arguments valid
     * @return true if json is valid, false otherwise
     */
    bool isValid() {return mValid;};

private:
    bool mValid = true;
    std::string mTaskName;
    std::string mTaskDescription;
    Task::Status mTaskStatus;
};

#endif // CREATETASKARGUMENTS_H
