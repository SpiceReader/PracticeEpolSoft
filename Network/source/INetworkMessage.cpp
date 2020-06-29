#include "INetworkMessage.h"

#include <iostream>

INetworkMessage::INetworkMessage()
{
    std::cout << "INetworkMessage constructor" << std::endl;
}

INetworkMessage::INetworkMessage(Json::Value message)
{
    this->mJsonMessage = message;
}

INetworkMessage::INetworkMessage(std::string message)
{
    this->mJsonMessage = Json::Value(message);
}

