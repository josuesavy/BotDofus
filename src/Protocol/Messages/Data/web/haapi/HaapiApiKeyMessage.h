#ifndef HAAPIAPIKEYMESSAGE_H
#define HAAPIAPIKEYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HaapiApiKeyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiApiKeyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiApiKeyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiApiKeyMessage(FuncTree tree);
  HaapiApiKeyMessage();

  QString token;

private:
  void _tokenFunc(Reader *input);
};

#endif // HAAPIAPIKEYMESSAGE_H