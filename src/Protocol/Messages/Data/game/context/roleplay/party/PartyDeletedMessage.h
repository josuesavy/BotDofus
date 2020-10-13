#ifndef PARTYDELETEDMESSAGE_H
#define PARTYDELETEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyDeletedMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyDeletedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyDeletedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyDeletedMessage(FuncTree tree);
  PartyDeletedMessage();
};

#endif // PARTYDELETEDMESSAGE_H