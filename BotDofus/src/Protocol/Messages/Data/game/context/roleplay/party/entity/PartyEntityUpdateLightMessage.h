#ifndef PARTYENTITYUPDATELIGHTMESSAGE_H
#define PARTYENTITYUPDATELIGHTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/PartyUpdateLightMessage.h"

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