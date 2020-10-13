#ifndef PARTYABDICATETHRONEMESSAGE_H
#define PARTYABDICATETHRONEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

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