#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "IMessageObserver.h"
#include "INetworkMessage.h"
#include "Request/Request.h"
#include "Response/Response.h"
#include "Request/CreateTaskArguments.h"
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

    static MessageHandler* getInstance();
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
    //void sendMessage();
    void setServerIp(std::string serverIp);

    void setServerPort(unsigned int serverPort);

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

    unsigned int getServerPort() const;

    Response getResponce() const;

    void setResponce(Response resp);

};


#endif // MESSAGEHANDLER_H
