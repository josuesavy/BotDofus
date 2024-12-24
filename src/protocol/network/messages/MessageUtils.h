#ifndef MESSAGEUTILS_H
#define MESSAGEUTILS_H

#include "src/utils/Public.h"
#include "src/protocol/network/messages/MessageEnum.h"

class MessageUtils
{
public:
  static QString getName(const MessageEnum &messageEnum);
};

#endif // MESSAGEUTILS_H