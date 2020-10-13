#ifndef HOUSEGUILDRIGHTSMESSAGE_H
#define HOUSEGUILDRIGHTSMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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