#ifndef PARTYINVITATIONDUNGEONDETAILSMESSAGE_H
#define PARTYINVITATIONDUNGEONDETAILSMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/PartyGuestInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/PartyInvitationDetailsMessage.h"

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