#ifndef GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE_H
#define GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
  QList<int> ticket;
  int homeServerId;

private:
  void _validTokenFunc(Reader *input);
  void _tickettreeFunc(Reader *input);
  void _ticketFunc(Reader *input);
  void _homeServerIdFunc(Reader *input);

  FuncTree _tickettree;
};

#endif // GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE_H