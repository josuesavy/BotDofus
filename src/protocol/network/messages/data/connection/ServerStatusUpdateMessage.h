#ifndef SERVERSTATUSUPDATEMESSAGE_H
#define SERVERSTATUSUPDATEMESSAGE_H

#include "src/protocol/network/types/data/connection/GameServerInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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