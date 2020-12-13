#ifndef PARTYPLEDGELOYALTYREQUESTMESSAGE_H
#define PARTYPLEDGELOYALTYREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyPledgeLoyaltyRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyPledgeLoyaltyRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyPledgeLoyaltyRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyPledgeLoyaltyRequestMessage(FuncTree tree);
  PartyPledgeLoyaltyRequestMessage();

  bool loyal;

private:
  void _loyalFunc(Reader *input);
};

#endif // PARTYPLEDGELOYALTYREQUESTMESSAGE_H