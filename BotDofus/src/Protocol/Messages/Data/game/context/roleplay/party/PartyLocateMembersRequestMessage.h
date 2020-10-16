#ifndef PARTYLOCATEMEMBERSREQUESTMESSAGE_H
#define PARTYLOCATEMEMBERSREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

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