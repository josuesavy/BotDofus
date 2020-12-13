#ifndef HOUSEGUILDRIGHTSMESSAGE_H
#define HOUSEGUILDRIGHTSMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HouseGuildRightsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseGuildRightsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseGuildRightsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseGuildRightsMessage(FuncTree tree);
  HouseGuildRightsMessage();

  uint houseId;
  uint instanceId;
  bool secondHand;
  QSharedPointer<GuildInformations> guildInfo;
  uint rights;

private:
  void _houseIdFunc(Reader *input);
  void _instanceIdFunc(Reader *input);
  void _secondHandFunc(Reader *input);
  void _guildInfotreeFunc(Reader *input);
  void _rightsFunc(Reader *input);

  FuncTree _guildInfotree;
};

#endif // HOUSEGUILDRIGHTSMESSAGE_H