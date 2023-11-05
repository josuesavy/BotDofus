#ifndef BREACHROOMUNLOCKRESULTMESSAGE_H
#define BREACHROOMUNLOCKRESULTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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