#ifndef SETENABLEAVAREQUESTMESSAGE_H
#define SETENABLEAVAREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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