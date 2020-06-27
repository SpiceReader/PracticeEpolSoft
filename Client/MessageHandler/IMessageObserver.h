#ifndef IMESSAGEOBSERVER_H
#define IMESSAGEOBSERVER_H

#include "Response/Response.h"

class IMessageObserver
{
public:
    /**
     * Called by MessageHandler when response from server is received
     * @param resp response from server
     */
    virtual void messageResponseReceived(const Response resp) = 0;
};

#endif // IMESSAGEOBSERVER_H
