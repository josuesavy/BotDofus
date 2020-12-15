#ifndef SERVERSLISTMESSAGE_H
#define SERVERSLISTMESSAGE_H

#include "src/protocol/types/data/connection/GameServerInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ServersListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServersListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServersListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServersListMessage(FuncTree tree);
  ServersListMessage();

  QList<GameServerInformations> servers;
  uint alreadyConnectedToServerId;
  bool canCreateNewCharacter;

private:
  void _serverstreeFunc(Reader *input);
  void _serversFunc(Reader *input);
  void _alreadyConnectedToServerIdFunc(Reader *input);
  void _canCreateNewCharacterFunc(Reader *input);

  FuncTree _serverstree;
};

#endif // SERVERSLISTMESSAGE_H