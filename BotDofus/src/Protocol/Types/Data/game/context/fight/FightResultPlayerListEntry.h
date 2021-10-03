#ifndef FIGHTRESULTPLAYERLISTENTRY_H
#define FIGHTRESULTPLAYERLISTENTRY_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/FightResultAdditionalData.h"
#include "src/protocol/types/data/game/context/fight/FightResultFighterListEntry.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightResultPlayerListEntry : public FightResultFighterListEntry
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightResultPlayerListEntry(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightResultPlayerListEntry(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightResultPlayerListEntry(FuncTree tree);
  FightResultPlayerListEntry();
  bool operator==(const FightResultPlayerListEntry &compared);

  uint level;
  QList<QSharedPointer<FightResultAdditionalData>> additional;

private:
  void _levelFunc(Reader *input);
  void _additionaltreeFunc(Reader *input);
  void _additionalFunc(Reader *input);

  FuncTree _additionaltree;
};

#endif // FIGHTRESULTPLAYERLISTENTRY_H