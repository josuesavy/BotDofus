#ifndef PARTYUPDATELIGHTMESSAGE_H
#define PARTYUPDATELIGHTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyUpdateLightMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyUpdateLightMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyUpdateLightMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyUpdateLightMessage(FuncTree tree);
  PartyUpdateLightMessage();

  double id;
  uint lifePoints;
  uint maxLifePoints;
  uint prospecting;
  uint regenRate;

private:
  void _idFunc(Reader *input);
  void _lifePointsFunc(Reader *input);
  void _maxLifePointsFunc(Reader *input);
  void _prospectingFunc(Reader *input);
  void _regenRateFunc(Reader *input);
};

#endif // PARTYUPDATELIGHTMESSAGE_H