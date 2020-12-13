#ifndef PRISMFIGHTREMOVEDMESSAGE_H
#define PRISMFIGHTREMOVEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismFightRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismFightRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismFightRemovedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismFightRemovedMessage(FuncTree tree);
  PrismFightRemovedMessage();

  uint subAreaId;

private:
  void _subAreaIdFunc(Reader *input);
};

#endif // PRISMFIGHTREMOVEDMESSAGE_H