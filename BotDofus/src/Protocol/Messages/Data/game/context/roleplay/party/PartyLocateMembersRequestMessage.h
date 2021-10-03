#ifndef PARTYLOCATEMEMBERSREQUESTMESSAGE_H
#define PARTYLOCATEMEMBERSREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyLocateMembersRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyLocateMembersRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyLocateMembersRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyLocateMembersRequestMessage(FuncTree tree);
  PartyLocateMembersRequestMessage();
};

#endif // PARTYLOCATEMEMBERSREQUESTMESSAGE_H