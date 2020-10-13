#ifndef HAAPISHOPAPIKEYREQUESTMESSAGE_H
#define HAAPISHOPAPIKEYREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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