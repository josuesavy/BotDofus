#ifndef CONSUMEALLGAMEACTIONITEMMESSAGE_H
#define CONSUMEALLGAMEACTIONITEMMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ConsumeAllGameActionItemMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ConsumeAllGameActionItemMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ConsumeAllGameActionItemMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ConsumeAllGameActionItemMessage(FuncTree tree);
  ConsumeAllGameActionItemMessage();

  double characterId;

private:
  void _characterIdFunc(Reader *input);
};

#endif // CONSUMEALLGAMEACTIONITEMMESSAGE_H