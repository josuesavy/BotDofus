#ifndef PARTYFOLLOWTHISMEMBERREQUESTMESSAGE_H
#define PARTYFOLLOWTHISMEMBERREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/PartyFollowMemberRequestMessage.h"

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