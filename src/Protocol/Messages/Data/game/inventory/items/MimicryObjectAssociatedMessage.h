#ifndef MIMICRYOBJECTASSOCIATEDMESSAGE_H
#define MIMICRYOBJECTASSOCIATEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/items/SymbioticObjectAssociatedMessage.h"

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