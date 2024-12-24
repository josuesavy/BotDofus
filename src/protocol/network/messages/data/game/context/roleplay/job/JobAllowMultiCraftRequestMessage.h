#ifndef JOBALLOWMULTICRAFTREQUESTMESSAGE_H
#define JOBALLOWMULTICRAFTREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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