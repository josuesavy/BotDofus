#ifndef PARTYFOLLOWTHISMEMBERREQUESTMESSAGE_H
#define PARTYFOLLOWTHISMEMBERREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/PartyFollowMemberRequestMessage.h"

class PartyFollowThisMemberRequestMessage : public PartyFollowMemberRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyFollowThisMemberRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyFollowThisMemberRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyFollowThisMemberRequestMessage(FuncTree tree);
  PartyFollowThisMemberRequestMessage();

  bool enabled;

private:
  void _enabledFunc(Reader *input);
};

#endif // PARTYFOLLOWTHISMEMBERREQUESTMESSAGE_H