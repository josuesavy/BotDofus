#ifndef PARTYKICKREQUESTMESSAGE_H
#define PARTYKICKREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

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