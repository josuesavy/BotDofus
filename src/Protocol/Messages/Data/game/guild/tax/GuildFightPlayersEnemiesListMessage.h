#ifndef GUILDFIGHTPLAYERSENEMIESLISTMESSAGE_H
#define GUILDFIGHTPLAYERSENEMIESLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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