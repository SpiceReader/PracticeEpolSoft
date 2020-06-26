#include "mainwindow.h"

#include <string>
#include <QApplication>
#include <json/json.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <vector>
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

        unsigned int commandCode = jsonValue["commandCode"].asUInt();
        Json::Value arguments = jsonValue["arguments"];

        std::cout << "Command code: " << commandCode << std::endl;
        std::cout << "Arguments: " << arguments << std::endl;

        std::string string_argument = arguments["string_argument"].asString();

        std::cout << "string_argument: " << string_argument << std::endl;

        Json::Value array_argument = arguments["array_argument"];
        for (unsigned int i = 0; i < array_argument.size(); i++)
        {
            std::string current = array_argument.get(i, "").asString();
            std::cout << current << std::endl;
        }

        std::vector<std::string> memberNames = jsonValue.getMemberNames();

        std::cout << "Member names" << std::endl;

        for (std::string cur : memberNames)
        {
            std::cout << cur << std::endl;
        }

        if (jsonValue.isObject())
        {
            std::cout << "Json value is object" << std::endl;
        }

        if (jsonValue.isString())
        {
            std::cout << "Json value is string" << std::endl;
        }
        else
        {
            std::cout << "Json value is not a string" << std::endl;
        }

        jsonValue["floatArgument"] = 1.25;

        jsonValue["emptyObject"] = Json::Value(Json::ValueType::objectValue);

        jsonValue["arrayObject"] = Json::Value(Json::arrayValue);

        jsonValue["arrayObject"].append("string");
        jsonValue["arrayObject"].append(1);
        jsonValue["arrayObject"].append(Json::Value(Json::objectValue));

        std::cout << "After new field is added: " << jsonValue << std::endl;

        Json::FastWriter writer;
        std::string json = writer.write(jsonValue);

        std::cout << "Json as string: " << json << std::endl;

        Json::Reader reader;
        Json::Value valueAfterParsing;

        reader.parse(json, valueAfterParsing);

        std::cout << "Json after conversion: " << valueAfterParsing << std::endl;
    }

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
}
