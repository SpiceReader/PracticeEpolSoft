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
    std::string str;
    QByteArray dataGet;
    QDataStream stream(&dataGet, QIODevice::ReadOnly);
    stream.setVersion(QDataStream::Qt_5_15);
    while (socket->canReadLine())
        {
            str = "";
            dataGet = socket->readLine(20);
            str = (dataGet.constData(), dataGet.length());
            messageToClient(socket, str);
        }
}

void Server::messageToClient(QTcpSocket *socket, const std::string& clientString)
{
    QString SomePrefix = "prefix";
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_15);
    stream << quint16(0) << QString::fromStdString(clientString) + SomePrefix << "\n";
    stream.device()->seek(0);   // set current, (write/read) from pos
    stream << quint16(data.size() - sizeof(quint16));

    socket->write(data);
}

void Server::clientDisconnect()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    qDebug("Disconnect!!");
    socket->close();
}
