#ifndef FIGHTRESULTPLAYERLISTENTRY_H
#define FIGHTRESULTPLAYERLISTENTRY_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultAdditionalData.h"
#include "src/Protocol/Types/Data/game/context/fight/FightResultFighterListEntry.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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