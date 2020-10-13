#ifndef BREACHROOMUNLOCKRESULTMESSAGE_H
#define BREACHROOMUNLOCKRESULTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BreachRoomUnlockResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachRoomUnlockResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachRoomUnlockResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachRoomUnlockResultMessage(FuncTree tree);
  BreachRoomUnlockResultMessage();

  uint roomId;
  uint result;

private:
  void _roomIdFunc(Reader *input);
  void _resultFunc(Reader *input);
};

#endif // BREACHROOMUNLOCKRESULTMESSAGE_H