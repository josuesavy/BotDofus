#ifndef PRISMFIGHTSTATEUPDATEMESSAGE_H
#define PRISMFIGHTSTATEUPDATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismFightStateUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismFightStateUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismFightStateUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismFightStateUpdateMessage(FuncTree tree);
  PrismFightStateUpdateMessage();

  uint state;

private:
  void _stateFunc(Reader *input);
};

#endif // PRISMFIGHTSTATEUPDATEMESSAGE_H