#ifndef HAAPIBUFFERLISTREQUESTMESSAGE_H
#define HAAPIBUFFERLISTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HaapiBufferListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiBufferListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiBufferListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiBufferListRequestMessage(FuncTree tree);
  HaapiBufferListRequestMessage();
};

#endif // HAAPIBUFFERLISTREQUESTMESSAGE_H