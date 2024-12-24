#ifndef PARTYLOYALTYSTATUSMESSAGE_H
#define PARTYLOYALTYSTATUSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyLoyaltyStatusMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyLoyaltyStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyLoyaltyStatusMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyLoyaltyStatusMessage(FuncTree tree);
  PartyLoyaltyStatusMessage();

  bool loyal;

private:
  void _loyalFunc(Reader *input);
};

#endif // PARTYLOYALTYSTATUSMESSAGE_H