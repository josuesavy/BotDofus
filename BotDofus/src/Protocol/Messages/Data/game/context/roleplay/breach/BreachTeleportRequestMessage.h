#ifndef BREACHTELEPORTREQUESTMESSAGE_H
#define BREACHTELEPORTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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