#ifndef PARTYINVITATIONDUNGEONMESSAGE_H
#define PARTYINVITATIONDUNGEONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/PartyInvitationMessage.h"

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