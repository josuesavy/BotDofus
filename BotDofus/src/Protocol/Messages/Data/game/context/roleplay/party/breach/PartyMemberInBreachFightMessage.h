#ifndef PARTYMEMBERINBREACHFIGHTMESSAGE_H
#define PARTYMEMBERINBREACHFIGHTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMemberInFightMessage.h"

class PartyMemberInBreachFightMessage : public AbstractPartyMemberInFightMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyMemberInBreachFightMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyMemberInBreachFightMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyMemberInBreachFightMessage(FuncTree tree);
  PartyMemberInBreachFightMessage();

  uint floor;
  uint room;

private:
  void _floorFunc(Reader *input);
  void _roomFunc(Reader *input);
};

#endif // PARTYMEMBERINBREACHFIGHTMESSAGE_H