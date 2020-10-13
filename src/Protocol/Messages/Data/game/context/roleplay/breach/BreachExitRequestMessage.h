#ifndef BREACHEXITREQUESTMESSAGE_H
#define BREACHEXITREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BreachExitRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachExitRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachExitRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachExitRequestMessage(FuncTree tree);
  BreachExitRequestMessage();
};

#endif // BREACHEXITREQUESTMESSAGE_H