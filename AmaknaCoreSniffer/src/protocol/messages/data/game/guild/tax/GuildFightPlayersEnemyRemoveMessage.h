#ifndef GUILDFIGHTPLAYERSENEMYREMOVEMESSAGE_H
#define GUILDFIGHTPLAYERSENEMYREMOVEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildFightPlayersEnemyRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFightPlayersEnemyRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFightPlayersEnemyRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFightPlayersEnemyRemoveMessage(FuncTree tree);
  GuildFightPlayersEnemyRemoveMessage();

  double fightId;
  double playerId;

private:
  void _fightIdFunc(Reader *input);
  void _playerIdFunc(Reader *input);
};

#endif // GUILDFIGHTPLAYERSENEMYREMOVEMESSAGE_H