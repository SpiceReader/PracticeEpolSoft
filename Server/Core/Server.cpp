#include "Core/Server.h"

Server::Server(unsigned int port)
{
    tcpserver = new QTcpServer(this);
    if (!tcpserver->listen(QHostAddress::LocalHost, port))
    {
        QMessageBox::critical(0, "Server Error", "Unable to start the server:" + tcpserver->errorString());
        tcpserver->close();
        return;
    }
    else
    {
        qDebug( "Starting succsefully!!!");
    }

    connect(tcpserver, SIGNAL(newConnection()), this, SLOT(clientConnection()));
}

void Server::clientConnection()
{
    QTcpSocket *tcpsocket = tcpserver->nextPendingConnection();
    if (tcpsocket == nullptr)
    {
        QMessageBox::critical(0, "Error", "Socket error!!");
    }
    tcpsocket->write("Connected succesfully!!");

    connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(getMessage()));
    connect(tcpsocket, SIGNAL(disconnected()), this, SLOT(clientDisconnect()));
}

void Server::getMessage()
{
    qDebug("Reading data!!");
    QTcpSocket *socket = (QTcpSocket*)sender();
    std::string str = "";
    QByteArray dataGet = 0;
    while (socket->bytesAvailable() > 0)
        {
            dataGet += socket->readAll();
        }
    socket->write(dataGet);
    qDebug() << dataGet;
    str = dataGet.toStdString();
    messageToClient(socket, str);
}

void Server::messageToClient(QTcpSocket *socket, const std::string& clientString)
{
    QByteArray data(clientString.c_str(), clientString.length());
    qDebug() << data;
    socket->write(data);
    socket->close();
}

void Server::clientDisconnect()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    qDebug("Disconnect!!");
    socket->close();
}
