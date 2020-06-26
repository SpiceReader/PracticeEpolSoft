#include "GUI/mainwindow.h"

#include <QApplication>
#include "INetworkMessage.h"

int main(int argc, char *argv[])
{
    INetworkMessage message;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
