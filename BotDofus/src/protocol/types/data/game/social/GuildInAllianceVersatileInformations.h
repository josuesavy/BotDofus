#ifndef GUILDINALLIANCEVERSATILEINFORMATIONS_H
#define GUILDINALLIANCEVERSATILEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/social/GuildVersatileInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildInAllianceVersatileInformations : public GuildVersatileInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInAllianceVersatileInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInAllianceVersatileInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInAllianceVersatileInformations(FuncTree tree);
  GuildInAllianceVersatileInformations();
  bool operator==(const GuildInAllianceVersatileInformations &compared);

  uint allianceId;

private:
  void _allianceIdFunc(Reader *input);
};

#endif // GUILDINALLIANCEVERSATILEINFORMATIONS_H