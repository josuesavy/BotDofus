#ifndef HOUSEGUILDEDINFORMATIONS_H
#define HOUSEGUILDEDINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Protocol/Types/Data/game/house/HouseInstanceInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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