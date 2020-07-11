#include "MessageHandler.h"

MessageHandler* MessageHandler::pInstance = nullptr;

void MessageHandler::sendMessage()
//void MessageHandler::sendMessage(Request request, IMessageObserver* observer)
{
    if (getServerIp() != "" && getServerPort() != 0)
    {
        CreateTaskArguments arguments("task_name", "task_description", Task::Status::OPEN);
        Json::Value jsonArguments = arguments.getJsonArguments();
        Request request(Request::CommandCode::CREATE_TASK, jsonArguments);
        Json::Value jsonMessage = request.getMessage();
        Json::FastWriter writter;
        std::string stringMessage = writter.write(jsonMessage);
        QByteArray req(stringMessage.c_str(), stringMessage.length());
        //QByteArray req(jsonMessage.asString().c_str(), jsonMessage.asString().length()); // get std::string from Json::Value

        QByteArray data = "String";
        socket = new QTcpSocket(this);
        socket->connectToHost ( QHostAddress(QString::fromStdString(getServerIp())), getServerPort());
        //socket->connectToHost (QHostAddress("127.0.0.1"), 666);


        //socket->write(req);
        socket->write(data);
        socket->write("Hello");


        connect(socket, SIGNAL(readyRead()), this, SLOT(readFromServer()));
        connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &MessageHandler::displayError);

      /*if (observer != nullptr)
        {
            observer->messageResponseReceived(getResponce());
        }*/
    }
    else {
        QMessageBox::information(this, tr("Client"),
                                 tr("Please check Ip and Port adresses."));
    }

    // Функция должна отправлять сообщение на сервер в отдельном потоке, ждать ответ, а затем закрывать соединение
    // Когда получен ответ, если observer - не nullptr, нужно вызвать метод observer->messageResponceReceived
    // и передать в него полученный ответ в виде объекта Response
    // Пул потоков использовать не нужно, каждый раз создавайте новый поток
    //
    // Примечание: перед отправкой нужно проверить, задал ли пользователь IP адрес и порт сервера в этом классе
}

void MessageHandler::readFromServer()
{

    qDebug("Reading server data!!");
    socket = (QTcpSocket*)sender();
    std::string str;
    QByteArray dataGet = 0;
    while (socket->bytesAvailable() > 0)
    {
        dataGet += socket->readAll();
    }
    qDebug() << dataGet;
    str = dataGet.toStdString();

    Json::Reader reader;
    Json::Value valueAfterParsing;
    reader.parse(str, valueAfterParsing);
    Response resp(valueAfterParsing);

    setResponce(resp);
}

void MessageHandler::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(socket->errorString()));
    }
    socket->close();
}

void MessageHandler::setResponce(Response resp)
{
    responce = &resp;
}

Response MessageHandler::getResponce() const
{
    return *responce;
}

MessageHandler* MessageHandler::getInstance()
{
    if(!pInstance)
        pInstance = new MessageHandler();
    return pInstance;
}

void MessageHandler::deleteInstance()
{
    delete pInstance;
}

std::string MessageHandler::getServerIp() const
{
    return ServerIpAdress;
}

void MessageHandler::setServerIp(std::string serverIp)
{
    ServerIpAdress = serverIp;
}

unsigned int MessageHandler::getServerPort() const
{
    return ServerPortAdress;
}

void MessageHandler::setServerPort(unsigned int serverPort)
{
    ServerPortAdress = serverPort;
}

