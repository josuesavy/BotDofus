#ifndef WRAPPEROBJECTASSOCIATEDMESSAGE_H
#define WRAPPEROBJECTASSOCIATEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/items/SymbioticObjectAssociatedMessage.h"

class WrapperObjectAssociatedMessage : public SymbioticObjectAssociatedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_WrapperObjectAssociatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_WrapperObjectAssociatedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_WrapperObjectAssociatedMessage(FuncTree tree);
  WrapperObjectAssociatedMessage();
};

#endif // WRAPPEROBJECTASSOCIATEDMESSAGE_H