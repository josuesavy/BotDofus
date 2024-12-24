#ifndef HAAPISHOPAPIKEYMESSAGE_H
#define HAAPISHOPAPIKEYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HaapiShopApiKeyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiShopApiKeyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiShopApiKeyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiShopApiKeyMessage(FuncTree tree);
  HaapiShopApiKeyMessage();

  QString token;

private:
  void _tokenFunc(Reader *input);
};

#endif // HAAPISHOPAPIKEYMESSAGE_H