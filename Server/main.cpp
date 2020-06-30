#include "mainwindow.h"
#include "Core/Server.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server ser(666);
    MainWindow w;
    w.show();
    return a.exec();
}
