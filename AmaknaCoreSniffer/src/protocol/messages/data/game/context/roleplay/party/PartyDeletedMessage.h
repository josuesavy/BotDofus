#ifndef PARTYDELETEDMESSAGE_H
#define PARTYDELETEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

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