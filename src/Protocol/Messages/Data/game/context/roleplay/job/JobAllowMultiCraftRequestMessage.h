#ifndef JOBALLOWMULTICRAFTREQUESTMESSAGE_H
#define JOBALLOWMULTICRAFTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class JobAllowMultiCraftRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobAllowMultiCraftRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobAllowMultiCraftRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobAllowMultiCraftRequestMessage(FuncTree tree);
  JobAllowMultiCraftRequestMessage();

  bool enabled;

private:
  void _enabledFunc(Reader *input);
};

#endif // JOBALLOWMULTICRAFTREQUESTMESSAGE_H