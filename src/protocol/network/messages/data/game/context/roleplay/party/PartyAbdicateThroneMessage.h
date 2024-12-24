#ifndef PARTYABDICATETHRONEMESSAGE_H
#define PARTYABDICATETHRONEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyAbdicateThroneMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyAbdicateThroneMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyAbdicateThroneMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyAbdicateThroneMessage(FuncTree tree);
  PartyAbdicateThroneMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // PARTYABDICATETHRONEMESSAGE_H