#ifndef REQUEST_H
#define REQUEST_H

#include "INetworkMessage.h"

/**
 * Represents request
 */
// Class Request should have methods to parse and store Command code from JSON
class Request : public INetworkMessage
{
public:
    /**
     * Defines possible command codes for request
     */
    enum CommandCode
    {
        LIST_OF_TASKS = 0,
        CREATE_TASK = 1,
        UPDATE_TASK = 2,
        DELETE_TASK = 3,
    };

    /**
     * Creates request from Json::Value message received from network
     * @param message Json::Value message
     */
    // В конструкторе нужно распарсить command_code, а message передать конструктору базы (INetworkMessage)
    Request(Json::Value message);

    /**
     * Creates request from string with JSON message
     * @param message string with JSON message
     */
    // Дополнительный конструктор, реализовать если требуется
    Request(std::string message);

    /**
     * Creates request with provided command code and arguments
     *
     * @param code command code
     * @param arguments Json::Value arguments
     */
    Request(CommandCode code, Json::Value arguments);

    /**
     * Return command code from object Request
     * @return commandCode from request
     */
    CommandCode getCommandCode();

    /**
     * Return field 'arguments' from Request
     * @return arguments
     */
    Json::Value getArguments();
};

#endif // REQUEST_H
