#ifndef PARTYINVITATIONDUNGEONMESSAGE_H
#define PARTYINVITATIONDUNGEONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/PartyInvitationMessage.h"

class PartyInvitationDungeonMessage : public PartyInvitationMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyInvitationDungeonMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyInvitationDungeonMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyInvitationDungeonMessage(FuncTree tree);
  PartyInvitationDungeonMessage();

  uint dungeonId;

private:
  void _dungeonIdFunc(Reader *input);
};

#endif // PARTYINVITATIONDUNGEONMESSAGE_H