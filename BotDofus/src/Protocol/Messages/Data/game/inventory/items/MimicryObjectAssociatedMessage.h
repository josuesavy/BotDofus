#ifndef MIMICRYOBJECTASSOCIATEDMESSAGE_H
#define MIMICRYOBJECTASSOCIATEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/items/SymbioticObjectAssociatedMessage.h"

class MimicryObjectAssociatedMessage : public SymbioticObjectAssociatedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MimicryObjectAssociatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MimicryObjectAssociatedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MimicryObjectAssociatedMessage(FuncTree tree);
  MimicryObjectAssociatedMessage();
};

#endif // MIMICRYOBJECTASSOCIATEDMESSAGE_H