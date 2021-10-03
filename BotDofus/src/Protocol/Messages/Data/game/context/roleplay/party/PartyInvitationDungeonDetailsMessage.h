#ifndef PARTYINVITATIONDUNGEONDETAILSMESSAGE_H
#define PARTYINVITATIONDUNGEONDETAILSMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "src/protocol/types/data/game/context/roleplay/party/PartyGuestInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/PartyInvitationDetailsMessage.h"

class PartyInvitationDungeonDetailsMessage : public PartyInvitationDetailsMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyInvitationDungeonDetailsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyInvitationDungeonDetailsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyInvitationDungeonDetailsMessage(FuncTree tree);
  PartyInvitationDungeonDetailsMessage();

  uint dungeonId;
  QList<bool> playersDungeonReady;

private:
  void _dungeonIdFunc(Reader *input);
  void _playersDungeonReadytreeFunc(Reader *input);
  void _playersDungeonReadyFunc(Reader *input);

  FuncTree _playersDungeonReadytree;
};

#endif // PARTYINVITATIONDUNGEONDETAILSMESSAGE_H