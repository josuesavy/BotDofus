#ifndef MIMICRYOBJECTFEEDANDASSOCIATEREQUESTMESSAGE_H
#define MIMICRYOBJECTFEEDANDASSOCIATEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/items/SymbioticObjectAssociateRequestMessage.h"

class MimicryObjectFeedAndAssociateRequestMessage : public SymbioticObjectAssociateRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MimicryObjectFeedAndAssociateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MimicryObjectFeedAndAssociateRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MimicryObjectFeedAndAssociateRequestMessage(FuncTree tree);
  MimicryObjectFeedAndAssociateRequestMessage();

  uint foodUID;
  uint foodPos;
  bool preview;

private:
  void _foodUIDFunc(Reader *input);
  void _foodPosFunc(Reader *input);
  void _previewFunc(Reader *input);
};

#endif // MIMICRYOBJECTFEEDANDASSOCIATEREQUESTMESSAGE_H