#ifndef PARTYKICKEDBYMESSAGE_H
#define PARTYKICKEDBYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

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