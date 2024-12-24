#ifndef OBTAINEDITEMMESSAGE_H
#define OBTAINEDITEMMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ObtainedItemMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObtainedItemMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObtainedItemMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObtainedItemMessage(FuncTree tree);
  ObtainedItemMessage();

  uint genericId;
  uint baseQuantity;

private:
  void _genericIdFunc(Reader *input);
  void _baseQuantityFunc(Reader *input);
};

#endif // OBTAINEDITEMMESSAGE_H