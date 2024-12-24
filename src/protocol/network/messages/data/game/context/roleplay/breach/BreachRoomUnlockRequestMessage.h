#ifndef BREACHROOMUNLOCKREQUESTMESSAGE_H
#define BREACHROOMUNLOCKREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class BreachRoomUnlockRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachRoomUnlockRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachRoomUnlockRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachRoomUnlockRequestMessage(FuncTree tree);
  BreachRoomUnlockRequestMessage();

  uint roomId;

private:
  void _roomIdFunc(Reader *input);
};

#endif // BREACHROOMUNLOCKREQUESTMESSAGE_H