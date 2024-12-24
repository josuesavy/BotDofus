#ifndef GAMEFIGHTSPECTATORJOINMESSAGE_H
#define GAMEFIGHTSPECTATORJOINMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/party/NamedPartyTeam.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/fight/GameFightJoinMessage.h"

class GameFightSpectatorJoinMessage : public GameFightJoinMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightSpectatorJoinMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightSpectatorJoinMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightSpectatorJoinMessage(FuncTree tree);
  GameFightSpectatorJoinMessage();

  QList<NamedPartyTeam> namedPartyTeams;

private:
  void _namedPartyTeamstreeFunc(Reader *input);
  void _namedPartyTeamsFunc(Reader *input);

  FuncTree _namedPartyTeamstree;
};

#endif // GAMEFIGHTSPECTATORJOINMESSAGE_H