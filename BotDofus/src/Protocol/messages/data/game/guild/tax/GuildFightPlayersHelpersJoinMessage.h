#ifndef GUILDFIGHTPLAYERSHELPERSJOINMESSAGE_H
#define GUILDFIGHTPLAYERSHELPERSJOINMESSAGE_H

#include "src/protocol/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildFightPlayersHelpersJoinMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFightPlayersHelpersJoinMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFightPlayersHelpersJoinMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFightPlayersHelpersJoinMessage(FuncTree tree);
  GuildFightPlayersHelpersJoinMessage();

  double fightId;
  QSharedPointer<CharacterMinimalPlusLookInformations> playerInfo;

private:
  void _fightIdFunc(Reader *input);
  void _playerInfotreeFunc(Reader *input);

  FuncTree _playerInfotree;
};

#endif // GUILDFIGHTPLAYERSHELPERSJOINMESSAGE_H