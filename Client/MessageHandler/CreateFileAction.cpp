#include "CreateFileAction.h"
#include "Request/Request.h"
#include "Request/CreateTaskArguments.h"
#include "MessageHandler.h"
#include "Response/Response.h"

CreateFileAction::CreateFileAction(Task &task)
{
    mTask = Task(task);
}

void CreateFileAction::executeAction()
{
    CreateTaskArguments arg(mTask);
    Request req(Request::CREATE_TASK, arg.getJsonArguments());
    //MessageHandler::getInstance()->sendMessage(req, this)
}

void CreateFileAction::setCallback(std::function<void (const Response &)> func)
{
    mFunction = func;
}

void CreateFileAction::messageResponseReceived(const Response resp)
{
    //if (resp)
    {

        mFunction(resp);
    }
}
