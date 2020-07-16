#include "GUI/mainwindow.h"
#include "QTcpSocket"
#include <QApplication>
#include "INetworkMessage.h"
#include "MessageHandler/IMessageObserver.h"
#include "MessageHandler/MessageHandler.h"

int main(int argc, char *argv[])
{
    INetworkMessage message;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MessageHandler MH;
    MH.getInstance();
    //MH.sendMessage();

    /*QTcpSocket clientsocket;
    QByteArray d, data = "String";
    //clientsocket.connectToHost(QHostAddress("127.0.0.1"), 666);
    clientsocket.write(data);
    data = "String111";
    clientsocket.write(data);
    data = "String222";
    clientsocket.write(data);*/

    return a.exec();
}
