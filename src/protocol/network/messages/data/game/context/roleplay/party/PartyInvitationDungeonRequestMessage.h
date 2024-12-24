#ifndef PARTYINVITATIONDUNGEONREQUESTMESSAGE_H
#define PARTYINVITATIONDUNGEONREQUESTMESSAGE_H

#include "src/protocol/network/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/PartyInvitationRequestMessage.h"

class PartyInvitationDungeonRequestMessage : public PartyInvitationRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyInvitationDungeonRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyInvitationDungeonRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyInvitationDungeonRequestMessage(FuncTree tree);
  PartyInvitationDungeonRequestMessage();

  uint dungeonId;

private:
  void _dungeonIdFunc(Reader *input);
};

#endif // PARTYINVITATIONDUNGEONREQUESTMESSAGE_H