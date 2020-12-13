#ifndef PARTYKICKEDBYMESSAGE_H
#define PARTYKICKEDBYMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyKickedByMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyKickedByMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyKickedByMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyKickedByMessage(FuncTree tree);
  PartyKickedByMessage();

  double kickerId;

private:
  void _kickerIdFunc(Reader *input);
};

#endif // PARTYKICKEDBYMESSAGE_H