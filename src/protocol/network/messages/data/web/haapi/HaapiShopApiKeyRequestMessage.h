#ifndef HAAPISHOPAPIKEYREQUESTMESSAGE_H
#define HAAPISHOPAPIKEYREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HaapiShopApiKeyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiShopApiKeyRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiShopApiKeyRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiShopApiKeyRequestMessage(FuncTree tree);
  HaapiShopApiKeyRequestMessage();
};

#endif // HAAPISHOPAPIKEYREQUESTMESSAGE_H