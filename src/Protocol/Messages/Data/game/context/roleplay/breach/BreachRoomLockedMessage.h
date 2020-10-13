#ifndef BREACHROOMLOCKEDMESSAGE_H
#define BREACHROOMLOCKEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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