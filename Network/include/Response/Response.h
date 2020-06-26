#ifndef RESPONSE_H
#define RESPONSE_H

#include "INetworkMessage.h"

class Response : public INetworkMessage
{
public:
    /**
     * Defines possible response codes for response
     */
    enum ResponseCode
    {
        SUCCESS
    };

    /**
     * Creates response with provided response code and empty arguments
     *
     * @param respCode response code
     */
    Response(ResponseCode respCode);

    /**
     * Creates response with Json::Value JSON message
     * @param message
     */
    // Конструктор должен парсить и сохранять response code из полученного сообщения
    Response(Json::Value message);

    /**
     * Creates response with provided response code and arguments
     * @param respCode response code
     * @param arguments JSON arguments
     */
    Response(ResponseCode respCode, Json::Value arguments);
};

#endif // RESPONSE_H
