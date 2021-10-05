#ifndef PADDOCKGUILDEDINFORMATIONS_H
#define PADDOCKGUILDEDINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/protocol/types/data/game/paddock/PaddockBuyableInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

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