#ifndef ABSTRACTGAMEACTIONMESSAGE_H
#define ABSTRACTGAMEACTIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AbstractGameActionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractGameActionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractGameActionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractGameActionMessage(FuncTree tree);
  AbstractGameActionMessage();

  uint actionId;
  double sourceId;

private:
  void _actionIdFunc(Reader *input);
  void _sourceIdFunc(Reader *input);
};

#endif // ABSTRACTGAMEACTIONMESSAGE_H