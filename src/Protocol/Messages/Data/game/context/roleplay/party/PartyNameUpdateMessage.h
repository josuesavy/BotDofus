#ifndef PARTYNAMEUPDATEMESSAGE_H
#define PARTYNAMEUPDATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

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