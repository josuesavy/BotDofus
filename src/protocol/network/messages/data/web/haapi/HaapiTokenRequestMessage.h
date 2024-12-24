#ifndef HAAPITOKENREQUESTMESSAGE_H
#define HAAPITOKENREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HaapiTokenRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiTokenRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiTokenRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiTokenRequestMessage(FuncTree tree);
  HaapiTokenRequestMessage();
};

#endif // HAAPITOKENREQUESTMESSAGE_H