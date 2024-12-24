#ifndef GAMEFIGHTUPDATETEAMMESSAGE_H
#define GAMEFIGHTUPDATETEAMMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/FightTeamInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightUpdateTeamMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightUpdateTeamMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightUpdateTeamMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightUpdateTeamMessage(FuncTree tree);
  GameFightUpdateTeamMessage();

  uint fightId;
  QSharedPointer<FightTeamInformations> team;

private:
  void _fightIdFunc(Reader *input);
  void _teamtreeFunc(Reader *input);

  FuncTree _teamtree;
};

#endif // GAMEFIGHTUPDATETEAMMESSAGE_H