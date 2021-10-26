#ifndef GLOBAL_H
#define GLOBAL_H

#include "src/engines/core/CoreEngine.h"

class Global : public CoreEngine
{
public:
    void printMessage(QString message, SocketIO *sender)
    {
        action(sender) << message;
    }

    void printSuccess(QString message, SocketIO *sender)
    {
        info(sender) << message;
    }

    void printWarning(QString message, SocketIO *sender)
    {
        warn(sender) << message;
    }

    void printError(QString message, SocketIO *sender)
    {
        error(sender) << message;
    }
};

#endif // GLOBAL_H
