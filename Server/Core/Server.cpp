#include "Server.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMessageBox>

Server::Server(unsigned int port)
{
    tcpserver = new QTcpServer(this);
    if (!tcpserver->listen(QHostAddress::Any, port))
    {
        QMessageBox::critical(0, "Server Error", "Unable to start the server:"
                                      + tcpserver->errorString());
        tcpserver->close();
        return;
    }
    connect(tcpserver, SIGNAL(newConnection()), this, SLOT(clientConnection()));
}

void Server::clientConnection()
{
    QTcpSocket *tcpsocket = tcpserver->nextPendingConnection();
    if (tcpsocket == nullptr)
    {
        QMessageBox::critical(0, "Error", "No pending connections!!");
    }

    connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(getMessage()));
    connect(tcpsocket, SIGNAL(disconnected()), tcpsocket, SLOT(deleteLater()));

    tcpsocket->write("Connected succesfully!!");

}

void Server::getMessage()
{

}

void Server::messageToClient(QTcpSocket *socket, const std::string& prefix)
{
    while(socket->bytesAvailable()>0)
       {
           QByteArray array = socket->readAll();
           socket->write(array);
       }
}
