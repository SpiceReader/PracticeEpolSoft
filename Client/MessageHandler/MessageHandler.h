#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "IMessageObserver.h"
#include "Request/Request.h"

/**
 * MessageHandler is used to send message to the server, receive a response
 * and notify observer when response is received
 *
 * Also it holds server IP and port
 */
// Реализовать в виде Singleton
class MessageHandler
{
public:
    /**
     * Returns singleton instance of MessageHandler
     * @return message handler instance
     */
    static MessageHandler* getInstance();

    /**
     * Deletes instance of MessageHandler. Used to clear memory when program terminates
     */
    static void deleteInstance();

    /**
     * Sends message to the server in separate thread
     *
     * @example MessageHandler::getInstance()->sendMessage(request, observer)
     *
     * @param request request to be sent to server
     * @param observer IMessageObserver to notify sender of message about answer from server
     */
    void sendMessage(Request request, IMessageObserver* observer);

    // Реализуйте методы сохранения и получения ip и порта в этом классе
    //getServerIp();
    //setServerIp(ip);
    //unsigned int getServerPort() const;
    //void setServerIp(unsigned int serverIp);

};

#endif // MESSAGEHANDLER_H
