#ifndef HAAPICONSUMEBUFFERREQUESTMESSAGE_H
#define HAAPICONSUMEBUFFERREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HaapiConsumeBufferRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiConsumeBufferRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiConsumeBufferRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiConsumeBufferRequestMessage(FuncTree tree);
  HaapiConsumeBufferRequestMessage();
};

#endif // HAAPICONSUMEBUFFERREQUESTMESSAGE_H