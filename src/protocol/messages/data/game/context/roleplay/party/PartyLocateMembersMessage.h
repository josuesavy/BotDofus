#ifndef PARTYLOCATEMEMBERSMESSAGE_H
#define PARTYLOCATEMEMBERSMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/party/PartyMemberGeoPosition.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

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