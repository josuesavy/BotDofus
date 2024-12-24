#ifndef PARTYMEMBERINSTANDARDFIGHTMESSAGE_H
#define PARTYMEMBERINSTANDARDFIGHTMESSAGE_H

#include "src/protocol/network/types/data/game/context/MapCoordinatesExtended.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/party/AbstractPartyMemberInFightMessage.h"

class PartyMemberInStandardFightMessage : public AbstractPartyMemberInFightMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyMemberInStandardFightMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyMemberInStandardFightMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyMemberInStandardFightMessage(FuncTree tree);
  PartyMemberInStandardFightMessage();

  QSharedPointer<MapCoordinatesExtended> fightMap;

private:
  void _fightMaptreeFunc(Reader *input);

  FuncTree _fightMaptree;
};

#endif // PARTYMEMBERINSTANDARDFIGHTMESSAGE_H