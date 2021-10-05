#ifndef BREACHROOMLOCKEDMESSAGE_H
#define BREACHROOMLOCKEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BreachRoomLockedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachRoomLockedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachRoomLockedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachRoomLockedMessage(FuncTree tree);
  BreachRoomLockedMessage();
};

#endif // BREACHROOMLOCKEDMESSAGE_H