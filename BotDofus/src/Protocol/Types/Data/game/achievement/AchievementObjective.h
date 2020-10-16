#ifndef ACHIEVEMENTOBJECTIVE_H
#define ACHIEVEMENTOBJECTIVE_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class AchievementObjective : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AchievementObjective(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AchievementObjective(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AchievementObjective(FuncTree tree);
  AchievementObjective();
  bool operator==(const AchievementObjective &compared);

  uint id;
  uint maxValue;

private:
  void _idFunc(Reader *input);
  void _maxValueFunc(Reader *input);
};

#endif // ACHIEVEMENTOBJECTIVE_H