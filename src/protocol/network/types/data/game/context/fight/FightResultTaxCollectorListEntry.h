#ifndef FIGHTRESULTTAXCOLLECTORLISTENTRY_H
#define FIGHTRESULTTAXCOLLECTORLISTENTRY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/protocol/types/data/game/context/fight/FightResultFighterListEntry.h"
#include "src/engines/io/network/utils/FuncTree.h"

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

  QSharedPointer<BasicAllianceInformations> allianceInfo;

private:
  void _allianceInfotreeFunc(Reader *input);

  FuncTree _allianceInfotree;
};

#endif // FIGHTRESULTTAXCOLLECTORLISTENTRY_H