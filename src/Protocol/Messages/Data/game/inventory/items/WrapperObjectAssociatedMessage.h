#ifndef WRAPPEROBJECTASSOCIATEDMESSAGE_H
#define WRAPPEROBJECTASSOCIATEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/items/SymbioticObjectAssociatedMessage.h"

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