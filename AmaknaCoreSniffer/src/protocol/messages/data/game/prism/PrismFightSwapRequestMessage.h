#ifndef PRISMFIGHTSWAPREQUESTMESSAGE_H
#define PRISMFIGHTSWAPREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismFightSwapRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismFightSwapRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismFightSwapRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismFightSwapRequestMessage(FuncTree tree);
  PrismFightSwapRequestMessage();

  uint subAreaId;
  double targetId;

private:
  void _subAreaIdFunc(Reader *input);
  void _targetIdFunc(Reader *input);
};

#endif // PRISMFIGHTSWAPREQUESTMESSAGE_H