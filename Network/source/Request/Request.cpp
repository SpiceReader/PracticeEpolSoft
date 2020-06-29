#include "Request/Request.h"

#include <iostream>

Request::Request(Json::Value message):
    INetworkMessage(message)
{
    std::cout << "Request constructor" << std::endl;
}

Request::Request(std::string message):
    INetworkMessage(message)
{
    std::cout << "Request constructor" << std::endl;
}

Json::Value parsingOfCommandCodeAndArguments(Request::CommandCode code, Json::Value arguments){
    Json::Value jsonValue;
    jsonValue["command_code"] = code;
    jsonValue["arguments"] = arguments;
    return jsonValue;
}

Request::Request(Request::CommandCode code, Json::Value arguments) :
    INetworkMessage(parsingOfCommandCodeAndArguments(code, arguments))
{
}

Request::CommandCode Request::getCommandCode()
{
    return static_cast<Request::CommandCode>(this->getMessage()["command_code"].asInt());
}
