#ifndef PARTYMEMBEREJECTEDMESSAGE_H
#define PARTYMEMBEREJECTEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/PartyMemberRemoveMessage.h"

class PartyMemberEjectedMessage : public PartyMemberRemoveMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyMemberEjectedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyMemberEjectedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyMemberEjectedMessage(FuncTree tree);
  PartyMemberEjectedMessage();

  double kickerId;

private:
  void _kickerIdFunc(Reader *input);
};

#endif // PARTYMEMBEREJECTEDMESSAGE_H