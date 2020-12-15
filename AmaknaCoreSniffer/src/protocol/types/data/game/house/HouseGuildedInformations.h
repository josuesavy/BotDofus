#ifndef HOUSEGUILDEDINFORMATIONS_H
#define HOUSEGUILDEDINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/protocol/types/data/game/house/HouseInstanceInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class HouseGuildedInformations : public HouseInstanceInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseGuildedInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseGuildedInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseGuildedInformations(FuncTree tree);
  HouseGuildedInformations();
  bool operator==(const HouseGuildedInformations &compared);

  QSharedPointer<GuildInformations> guildInfo;

private:
  void _guildInfotreeFunc(Reader *input);

  FuncTree _guildInfotree;
};

#endif // HOUSEGUILDEDINFORMATIONS_H