#ifndef UPDATETASKARGUMENTS_H
#define UPDATETASKARGUMENTS_H

#include <string>
#include "Task/Task.h"
#include "json/json.h"

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
     * @param taskId Id of updated task
     * @brief Creates arguments from task in memory
     * @param task Object of Task class
     */
    UpdateTaskArguments(unsigned int taskId, Task& task);

    /**
     * @brief Convert all arguments to json object
     * @return Json object with fields, needed to update task
     */
    Json::Value getJsonArguments();

private:
    unsigned int mTaskId;
    std::string mTaskName;
    std::string mTaskDescription;
    Task::Status mTaskStatus;
};

#endif // UPDATETASKARGUMENTS_H
