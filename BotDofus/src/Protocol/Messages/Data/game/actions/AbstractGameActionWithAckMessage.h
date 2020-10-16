#ifndef ABSTRACTGAMEACTIONWITHACKMESSAGE_H
#define ABSTRACTGAMEACTIONWITHACKMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/AbstractGameActionMessage.h"

class AbstractGameActionWithAckMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractGameActionWithAckMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractGameActionWithAckMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractGameActionWithAckMessage(FuncTree tree);
  AbstractGameActionWithAckMessage();

  int waitAckId;

private:
  void _waitAckIdFunc(Reader *input);
};

#endif // ABSTRACTGAMEACTIONWITHACKMESSAGE_H