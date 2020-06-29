#ifndef DELETETASKARGUMENTS_H
#define DELETETASKARGUMENTS_H

#include <string>
#include <Task/Task.h>
#include <json/json.h>

class DeleteTaskArguments
{
public:
    /**
     * @brief Creates arguments which needed to be used in request
     * @param taskId Id of deleted task
     */
    DeleteTaskArguments(unsigned int taskId);

    /**
     * @brief Convert all arguments to json object
     * @return Json object with fields, needed to delete task
     */
    Json::Value getJsonArguments();

private:
    unsigned int mTaskId;
};

#endif // DELETETASKARGUMENTS_H
