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

    std::function<void()> client = [=] () { connect(tcpserver, SIGNAL(newConnection()), this, SLOT(clientConnection())); };
    thread = new ThreadPool();
    thread->addTask(client);
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
    connect(tcpsocket, SIGNAL(disconnected()), tcpsocket, SLOT(deleteLater()));
}

void Server::getMessage()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_15);

    while (true) {
        QString str;
        if (socket->bytesAvailable() > 0) {
            socket->readAll();
            stream >> str;
        }
        else {
            break;
        }
        messageToClient(socket, str);
    }
}

void Server::messageToClient(QTcpSocket *socket, const QString& clientString)
{
    QString SomePrefix;
    QByteArray data;
    QDataStream stream (&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_15);
    stream << quint16(0) << clientString + SomePrefix;

    stream.device()->seek(0);   // set current, (write/read) from pos
    stream << quint16(data.size() - sizeof(quint16));

    socket->write(data);
}
