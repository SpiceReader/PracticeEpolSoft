#include "mainwindow.h"

#include <string>
#include <QApplication>
#include <json/json.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <Windows.h>

int main(int argc, char *argv[])
{
    if(argc > 0)
    {
        // Get path to directory where is the executable file
        std::string urlK = argv[0];

        urlK.erase(urlK.find_last_of('\\'));

        SetCurrentDirectoryA(urlK.c_str());
    }


    std::ifstream file;
    file.open("jsonExample.txt");
    if(file.is_open())
    {
        Json::Value jsonValue;
        file >> jsonValue;
        file.close();

        std::cout << jsonValue << std::endl;
    }

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
}
