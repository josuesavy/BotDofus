#ifndef PORTALUSEREQUESTMESSAGE_H
#define PORTALUSEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PortalUseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PortalUseRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PortalUseRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PortalUseRequestMessage(FuncTree tree);
  PortalUseRequestMessage();

  uint portalId;

private:
  void _portalIdFunc(Reader *input);
};

#endif // PORTALUSEREQUESTMESSAGE_H