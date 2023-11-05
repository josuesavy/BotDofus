#ifndef PRISMTELEPORTATIONREQUESTMESSAGE_H
#define PRISMTELEPORTATIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismTeleportationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismTeleportationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismTeleportationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismTeleportationRequestMessage(FuncTree tree);
  PrismTeleportationRequestMessage();
};

#endif // PRISMTELEPORTATIONREQUESTMESSAGE_H