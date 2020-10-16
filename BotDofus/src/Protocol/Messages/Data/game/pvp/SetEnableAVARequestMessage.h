#ifndef SETENABLEAVAREQUESTMESSAGE_H
#define SETENABLEAVAREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class SetEnableAVARequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SetEnableAVARequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SetEnableAVARequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SetEnableAVARequestMessage(FuncTree tree);
  SetEnableAVARequestMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // SETENABLEAVAREQUESTMESSAGE_H