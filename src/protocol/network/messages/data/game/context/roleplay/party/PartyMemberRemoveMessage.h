#ifndef PARTYMEMBERREMOVEMESSAGE_H
#define PARTYMEMBERREMOVEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyMemberRemoveMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyMemberRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyMemberRemoveMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyMemberRemoveMessage(FuncTree tree);
  PartyMemberRemoveMessage();

  double leavingPlayerId;

private:
  void _leavingPlayerIdFunc(Reader *input);
};

#endif // PARTYMEMBERREMOVEMESSAGE_H