#ifndef PARTYRESTRICTEDMESSAGE_H
#define PARTYRESTRICTEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyRestrictedMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyRestrictedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyRestrictedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyRestrictedMessage(FuncTree tree);
  PartyRestrictedMessage();

  bool restricted;

private:
  void _restrictedFunc(Reader *input);
};

#endif // PARTYRESTRICTEDMESSAGE_H