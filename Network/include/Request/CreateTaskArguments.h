#ifndef CREATETASKARGUMENTS_H
#define CREATETASKARGUMENTS_H

#include <string>
#include <Task/Task.h>
#include <json/json.h>

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
     * @brief Convert all arguments to json object
     * @return Json object with fields, needed to create task
     */
    Json::Value getJsonArguments();

private:
    std::string mTaskName;
    std::string mTaskDescription;
    Task::Status mTaskStatus;
};

#endif // CREATETASKARGUMENTS_H
