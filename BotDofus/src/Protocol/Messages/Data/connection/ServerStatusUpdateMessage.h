#ifndef SERVERSTATUSUPDATEMESSAGE_H
#define SERVERSTATUSUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/connection/GameServerInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ServerStatusUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServerStatusUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServerStatusUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServerStatusUpdateMessage(FuncTree tree);
  ServerStatusUpdateMessage();

  GameServerInformations server;

private:
  void _servertreeFunc(Reader *input);

  FuncTree _servertree;
};

#endif // SERVERSTATUSUPDATEMESSAGE_H