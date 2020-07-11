#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "IMessageObserver.h"
#include "INetworkMessage.h"
#include "Request/Request.h"
#include "Response/Response.h"
#include "Request/CreateTaskArguments.h"
#include <thread>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <string>
#include <QHostAddress>
#include <QObject>
#include <QMessageBox>

/**
 * MessageHandler is used to send message to the server, receive a response
 * Also it holds server IP and port
 */
// Реализовать в виде Singleton
class MessageHandler : public QMessageBox
{
    Q_OBJECT

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

    //void sendMessage(Request request, IMessageObserver* observer);
    void sendMessage();

private slots:
    void readFromServer();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    static MessageHandler* pInstance;
    QTcpSocket *socket;
    std::string ServerIpAdress = "127.0.0.1";
    unsigned int ServerPortAdress = 666;
    Response *responce;


    std::string getServerIp() const;

    void setServerIp(std::string serverIp);

    unsigned int getServerPort() const;

    void setServerPort(unsigned int serverPort);

    Response getResponce() const;

    void setResponce(Response resp);

    // Реализуйте методы сохранения и получения ip и порта в этом классе
    //getServerIp();
    //setServerIp(ip);
    //unsigned int getServerPort() const;
    //void setServerIp(unsigned int serverIp);

};


#endif // MESSAGEHANDLER_H
