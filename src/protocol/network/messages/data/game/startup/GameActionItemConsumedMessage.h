#ifndef GAMEACTIONITEMCONSUMEDMESSAGE_H
#define GAMEACTIONITEMCONSUMEDMESSAGE_H

#include "src/utils/io/type/BooleanByteWrapper.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameActionItemConsumedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionItemConsumedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionItemConsumedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionItemConsumedMessage(FuncTree tree);
  GameActionItemConsumedMessage();

  bool success;
  uint actionId;
  bool automaticAction;

private:
  void deserializeByteBoxes(Reader *input);
  void _actionIdFunc(Reader *input);
};

#endif // GAMEACTIONITEMCONSUMEDMESSAGE_H