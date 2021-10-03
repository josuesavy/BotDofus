#ifndef PRISMSETSABOTAGEDREQUESTMESSAGE_H
#define PRISMSETSABOTAGEDREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismSetSabotagedRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismSetSabotagedRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismSetSabotagedRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismSetSabotagedRequestMessage(FuncTree tree);
  PrismSetSabotagedRequestMessage();

  uint subAreaId;

private:
  void _subAreaIdFunc(Reader *input);
};

#endif // PRISMSETSABOTAGEDREQUESTMESSAGE_H