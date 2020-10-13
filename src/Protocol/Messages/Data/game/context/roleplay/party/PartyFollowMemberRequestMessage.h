#ifndef PARTYFOLLOWMEMBERREQUESTMESSAGE_H
#define PARTYFOLLOWMEMBERREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyFollowMemberRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyFollowMemberRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyFollowMemberRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyFollowMemberRequestMessage(FuncTree tree);
  PartyFollowMemberRequestMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // PARTYFOLLOWMEMBERREQUESTMESSAGE_H