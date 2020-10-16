#ifndef GAMEFIGHTSPECTATORJOINMESSAGE_H
#define GAMEFIGHTSPECTATORJOINMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/party/NamedPartyTeam.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/fight/GameFightJoinMessage.h"

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