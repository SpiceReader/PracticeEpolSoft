#include "mainwindow.h"

#include <string>
#include <QApplication>
#include <json/json.h>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
    std::ifstream json_file("jsonExample.txt");
    Json::Value jsonValue;
    json_file >> jsonValue;
    json_file.close();

    std::cout << jsonValue["arguments"] << std::endl;

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
}
