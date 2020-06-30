#ifndef DELETETASKARGUMENTS_H
#define DELETETASKARGUMENTS_H

#include <string>
#include <Task/Task.h>
#include <json/json.h>
#include "Request.h"

class DeleteTaskArguments
{
public:
    /**
     * @brief Creates arguments which needed to be used in request
     * @param taskId Id of deleted task
     */
    DeleteTaskArguments(unsigned int taskId);

    /**
     * @brief Creates arguments which needed to be used in request
     * @param jsonValue Object of JSON with fields to delete Task
     */
    DeleteTaskArguments(Json::Value& jsonValue);

    /**
     * @brief Creates arguments which needed to be used in request
     * @param request JSON object with fields CommandCode and Arguments
     */
    DeleteTaskArguments(Request& request);

    /**
     * @brief Convert all arguments to json object
     * @return Json object with fields, needed to delete task
     */
    Json::Value getJsonArguments();

private:
    unsigned int mTaskId;
};

#endif // DELETETASKARGUMENTS_H
