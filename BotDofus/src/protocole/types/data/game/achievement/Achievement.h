#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/achievement/AchievementObjective.h"
#include "src/protocol/types/data/game/achievement/AchievementStartedObjective.h"
#include "src/engines/io/network/utils/FuncTree.h"

class Achievement : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_Achievement(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_Achievement(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_Achievement(FuncTree tree);
  Achievement();
  bool operator==(const Achievement &compared);

  uint id;
  QList<AchievementObjective> finishedObjective;
  QList<AchievementStartedObjective> startedObjectives;

private:
  void _idFunc(Reader *input);
  void _finishedObjectivetreeFunc(Reader *input);
  void _finishedObjectiveFunc(Reader *input);
  void _startedObjectivestreeFunc(Reader *input);
  void _startedObjectivesFunc(Reader *input);

  FuncTree _finishedObjectivetree;
  FuncTree _startedObjectivestree;
};

#endif // ACHIEVEMENT_H