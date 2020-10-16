#ifndef MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE_H
#define MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/party/NamedPartyTeam.h"
#include "src/Protocol/Types/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/MapRunningFightDetailsMessage.h"

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