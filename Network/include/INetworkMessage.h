#ifndef INETWORKMESSAGE_H
#define INETWORKMESSAGE_H

#include <json/json.h>
#include <string>

/**
 * Represents interface to define a network message (request or response)
 */
// Концепт JSON парсера:
//
// INetworkMessage - интерфейс, который представляет сообщение. От него наследуются классы Request и Response
//
// Request будет парсить поле command_code
// Response будет парсить response_code
//
// Необходимо будет реализовать дополнительные классы с префиксом Arguments для аргументов конкретного типа
//
// Использование этой структуры в коде:
//
// При отправке запроса от клиента к серверу
// -----------------------------------------
//
// CreateTaskArguments arguments("task_name", "task_description", Task::Status::OPEN);
// Json::Value jsonArguments = arguments.getJsonArguments();
// Request request(Request::CommandCode::CREATE_TASK, jsonArguments)
// Json::Value jsonMessage = request.getMessage()
//
// При получении сообщения на сервере
// ----------------------------------
//
// std::string stringWithJson; // Строка с JSON, полученная из сокета
// Json::Reader reader;
// Json::Value valueAfterParsing;
// reader.parse(stringWithJson, valueAfterParsing);
// Request req(valueAfterParsing);
// if (req.getCommandCode() == Request::CommandCode::CREATE_FILE)
// {
//    // Обработка создания таска
// }
class INetworkMessage
{
public:
    INetworkMessage();

    /**
     * Constructs network message with JSON received from network
     *
     * @param message Json::Value message
     */
    //INetworkMessage(Json::Value message);

    /**
     * Constructs network message from string with JSON
     *
     * @param message string with JSON message
     */
    // Дополнительный конструктор, реализовать если требуется
    //INetworkMessage(std::string message);

    /**
     * Used to obtain JSON message
     *
     * @return Json::Value message
     */
    //Json::Value getMessage();

private:
    /**
     * Used to store JSON data
     */
    Json::Value mJsonMessage;
};

#endif // INETWORKMESSAGE_H
