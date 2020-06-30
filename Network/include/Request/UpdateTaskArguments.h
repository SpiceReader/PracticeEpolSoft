#ifndef UPDATETASKARGUMENTS_H
#define UPDATETASKARGUMENTS_H

#include <string>
#include "Task/Task.h"
#include "json/json.h"
#include "Request.h"

class UpdateTaskArguments
{
public:
    /**
     * @brief Creates arguments which needed to be used in request
     * @param taskId Id of updated task
     * @param taskName Name of updated task
     * @param taskDescription Desciption of updated task
     * @param status Status of updated task
     */
    UpdateTaskArguments(unsigned int taskId, std::string taskName, std::string taskDescription, Task::Status status);

    /**
     * @brief Creates arguments from task in memory
     * @param taskId Id of updated task
     * @param task Object of Task class
     */
    UpdateTaskArguments(unsigned int taskId, Task& task);

    /**
     * @brief Creates arguments from JSON
     * @param jsonValue Object of JSON with fields to update Task
     */
    UpdateTaskArguments(Json::Value& jsonValue);

    /**
     * @brief Creates arguments from JSON
     * @param request JSON object of JSON with fields CommandCode and Arguments
     */
    UpdateTaskArguments(Request& request);

    /**
     * @brief Convert all arguments to json object
     * @return Json object with fields, needed to update task
     */
    Json::Value getJsonArguments();

    /**
     * @brief Check if json arguments valid
     * @return true if json is valid, false otherwise
     */
    bool isValid() {return mValid;};

private:
    bool mValid = true;
    unsigned int mTaskId;
    std::string mTaskName;
    std::string mTaskDescription;
    Task::Status mTaskStatus;
};

#endif // UPDATETASKARGUMENTS_H
