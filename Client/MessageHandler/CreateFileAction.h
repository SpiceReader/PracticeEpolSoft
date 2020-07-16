#ifndef CREATEFILEACTION_H
#define CREATEFILEACTION_H

#include "Task/Task.h"
#include "IMessageObserver.h"
#include <functional>

class CreateFileAction : public IMessageObserver
{
public:
    CreateFileAction(Task &task);

    void executeAction();
    void setCallback(std::function<void(const Response&)> func);

    // IMessageObserver interface
private:
    void messageResponseReceived(const Response resp);

    Task mTask;
    std::function<void(const Response&)> mFunction;
};

#endif // CREATEFILEACTION_H
