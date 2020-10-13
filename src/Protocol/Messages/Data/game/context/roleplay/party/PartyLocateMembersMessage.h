#ifndef PARTYLOCATEMEMBERSMESSAGE_H
#define PARTYLOCATEMEMBERSMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/party/PartyMemberGeoPosition.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyLocateMembersMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyLocateMembersMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyLocateMembersMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyLocateMembersMessage(FuncTree tree);
  PartyLocateMembersMessage();

  QList<PartyMemberGeoPosition> geopositions;

private:
  void _geopositionstreeFunc(Reader *input);
  void _geopositionsFunc(Reader *input);

  FuncTree _geopositionstree;
};

#endif // PARTYLOCATEMEMBERSMESSAGE_H