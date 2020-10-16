#ifndef SETENABLEPVPREQUESTMESSAGE_H
#define SETENABLEPVPREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class SetEnablePVPRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SetEnablePVPRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SetEnablePVPRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SetEnablePVPRequestMessage(FuncTree tree);
  SetEnablePVPRequestMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // SETENABLEPVPREQUESTMESSAGE_H