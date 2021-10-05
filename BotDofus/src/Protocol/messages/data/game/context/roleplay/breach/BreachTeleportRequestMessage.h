#ifndef BREACHTELEPORTREQUESTMESSAGE_H
#define BREACHTELEPORTREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BreachTeleportRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachTeleportRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachTeleportRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachTeleportRequestMessage(FuncTree tree);
  BreachTeleportRequestMessage();
};

#endif // BREACHTELEPORTREQUESTMESSAGE_H