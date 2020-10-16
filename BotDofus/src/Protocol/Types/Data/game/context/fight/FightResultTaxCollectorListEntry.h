#ifndef FIGHTRESULTTAXCOLLECTORLISTENTRY_H
#define FIGHTRESULTTAXCOLLECTORLISTENTRY_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicGuildInformations.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultFighterListEntry.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightResultTaxCollectorListEntry : public FightResultFighterListEntry
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightResultTaxCollectorListEntry(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightResultTaxCollectorListEntry(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightResultTaxCollectorListEntry(FuncTree tree);
  FightResultTaxCollectorListEntry();
  bool operator==(const FightResultTaxCollectorListEntry &compared);

  uint level;
  QSharedPointer<BasicGuildInformations> guildInfo;
  int experienceForGuild;

private:
  void _levelFunc(Reader *input);
  void _guildInfotreeFunc(Reader *input);
  void _experienceForGuildFunc(Reader *input);

  FuncTree _guildInfotree;
};

#endif // FIGHTRESULTTAXCOLLECTORLISTENTRY_H