#include "GUI/mainwindow.h"
#include "QTcpSocket"
#include <QApplication>
#include "QTcpServer"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QTcpSocket clientsocket;
    clientsocket.connectToHost(QHostAddress("127.0.0.1"), 666);
    clientsocket.write("TheString");

    return a.exec();
}
