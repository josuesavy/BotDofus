#ifndef CURRENTSERVERSTATUSUPDATEMESSAGE_H
#define CURRENTSERVERSTATUSUPDATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CurrentServerStatusUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CurrentServerStatusUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CurrentServerStatusUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CurrentServerStatusUpdateMessage(FuncTree tree);
  CurrentServerStatusUpdateMessage();

  uint status;

private:
  void _statusFunc(Reader *input);
};

#endif // CURRENTSERVERSTATUSUPDATEMESSAGE_H