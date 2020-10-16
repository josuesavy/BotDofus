#ifndef PADDOCKGUILDEDINFORMATIONS_H
#define PADDOCKGUILDEDINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Protocol/Types/Data/game/paddock/PaddockBuyableInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class PaddockGuildedInformations : public PaddockBuyableInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockGuildedInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockGuildedInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockGuildedInformations(FuncTree tree);
  PaddockGuildedInformations();
  bool operator==(const PaddockGuildedInformations &compared);

  bool deserted;
  QSharedPointer<GuildInformations> guildInfo;

private:
  void _desertedFunc(Reader *input);
  void _guildInfotreeFunc(Reader *input);

  FuncTree _guildInfotree;
};

#endif // PADDOCKGUILDEDINFORMATIONS_H