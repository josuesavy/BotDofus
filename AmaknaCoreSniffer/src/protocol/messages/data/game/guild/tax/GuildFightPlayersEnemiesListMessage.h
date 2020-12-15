#ifndef GUILDFIGHTPLAYERSENEMIESLISTMESSAGE_H
#define GUILDFIGHTPLAYERSENEMIESLISTMESSAGE_H

#include "src/protocol/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildFightPlayersEnemiesListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFightPlayersEnemiesListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFightPlayersEnemiesListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFightPlayersEnemiesListMessage(FuncTree tree);
  GuildFightPlayersEnemiesListMessage();

  double fightId;
  QList<QSharedPointer<CharacterMinimalPlusLookInformations>> playerInfo;

private:
  void _fightIdFunc(Reader *input);
  void _playerInfotreeFunc(Reader *input);
  void _playerInfoFunc(Reader *input);

  FuncTree _playerInfotree;
};

#endif // GUILDFIGHTPLAYERSENEMIESLISTMESSAGE_H