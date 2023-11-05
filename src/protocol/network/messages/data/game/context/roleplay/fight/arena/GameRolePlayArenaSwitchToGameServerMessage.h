#ifndef GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE_H
#define GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameRolePlayArenaSwitchToGameServerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayArenaSwitchToGameServerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayArenaSwitchToGameServerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayArenaSwitchToGameServerMessage(FuncTree tree);
  GameRolePlayArenaSwitchToGameServerMessage();

  bool validToken;
  QString token;
  int homeServerId;

private:
  void _validTokenFunc(Reader *input);
  void _tokenFunc(Reader *input);
  void _homeServerIdFunc(Reader *input);
};

#endif // GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE_H