#ifndef CONSUMEGAMEACTIONITEMMESSAGE_H
#define CONSUMEGAMEACTIONITEMMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ConsumeGameActionItemMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ConsumeGameActionItemMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ConsumeGameActionItemMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ConsumeGameActionItemMessage(FuncTree tree);
  ConsumeGameActionItemMessage();

  uint actionId;
  double characterId;

private:
  void _actionIdFunc(Reader *input);
  void _characterIdFunc(Reader *input);
};

#endif // CONSUMEGAMEACTIONITEMMESSAGE_H