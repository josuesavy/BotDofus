#ifndef MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE_H
#define MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/NamedPartyTeam.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/MapRunningFightDetailsMessage.h"

class MapRunningFightDetailsExtendedMessage : public MapRunningFightDetailsMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapRunningFightDetailsExtendedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapRunningFightDetailsExtendedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapRunningFightDetailsExtendedMessage(FuncTree tree);
  MapRunningFightDetailsExtendedMessage();

  QList<NamedPartyTeam> namedPartyTeams;

private:
  void _namedPartyTeamstreeFunc(Reader *input);
  void _namedPartyTeamsFunc(Reader *input);

  FuncTree _namedPartyTeamstree;
};

#endif // MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE_H