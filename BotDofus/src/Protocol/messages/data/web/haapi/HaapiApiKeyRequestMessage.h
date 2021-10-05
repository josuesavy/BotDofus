#ifndef HAAPIAPIKEYREQUESTMESSAGE_H
#define HAAPIAPIKEYREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HaapiApiKeyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiApiKeyRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiApiKeyRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiApiKeyRequestMessage(FuncTree tree);
  HaapiApiKeyRequestMessage();
};

#endif // HAAPIAPIKEYREQUESTMESSAGE_H