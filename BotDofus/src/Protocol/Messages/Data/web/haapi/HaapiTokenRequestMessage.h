#ifndef HAAPITOKENREQUESTMESSAGE_H
#define HAAPITOKENREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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