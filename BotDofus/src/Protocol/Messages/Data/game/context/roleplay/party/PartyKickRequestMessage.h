#ifndef PARTYKICKREQUESTMESSAGE_H
#define PARTYKICKREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyKickRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyKickRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyKickRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyKickRequestMessage(FuncTree tree);
  PartyKickRequestMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // PARTYKICKREQUESTMESSAGE_H