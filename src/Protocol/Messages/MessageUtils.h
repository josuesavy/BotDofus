#ifndef MESSAGEUTILS_H
#define MESSAGEUTILS_H

#include "src/Public.h"
#include "src/Protocol/Messages/MessageEnum.h"

class MessageUtils
{
public:
  static QString getName(const MessageEnum &messageEnum);
};

#endif // MESSAGEUTILS_H