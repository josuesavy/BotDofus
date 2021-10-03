#ifndef PRISMATTACKREQUESTMESSAGE_H
#define PRISMATTACKREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismAttackRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismAttackRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismAttackRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismAttackRequestMessage(FuncTree tree);
  PrismAttackRequestMessage();
};

#endif // PRISMATTACKREQUESTMESSAGE_H