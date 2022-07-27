#ifndef PARTYENTITYUPDATELIGHTMESSAGE_H
#define PARTYENTITYUPDATELIGHTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/PartyUpdateLightMessage.h"

class PartyEntityUpdateLightMessage : public PartyUpdateLightMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyEntityUpdateLightMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyEntityUpdateLightMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyEntityUpdateLightMessage(FuncTree tree);
  PartyEntityUpdateLightMessage();

  uint indexId;

private:
  void _indexIdFunc(Reader *input);
};

#endif // PARTYENTITYUPDATELIGHTMESSAGE_H