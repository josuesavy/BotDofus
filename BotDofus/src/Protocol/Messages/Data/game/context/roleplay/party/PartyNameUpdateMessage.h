#ifndef PARTYNAMEUPDATEMESSAGE_H
#define PARTYNAMEUPDATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyNameUpdateMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyNameUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyNameUpdateMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyNameUpdateMessage(FuncTree tree);
  PartyNameUpdateMessage();

  QString partyName;

private:
  void _partyNameFunc(Reader *input);
};

#endif // PARTYNAMEUPDATEMESSAGE_H