#ifndef HUMANOPTIONSKILLUSE_H
#define HUMANOPTIONSKILLUSE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOption.h"
#include "src/utils/io/type/FuncTree.h"

class HumanOptionSkillUse : public HumanOption
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanOptionSkillUse(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanOptionSkillUse(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanOptionSkillUse(FuncTree tree);
  HumanOptionSkillUse();
  bool operator==(const HumanOptionSkillUse &compared);

  uint elementId;
  uint skillId;
  double skillEndTime;

private:
  void _elementIdFunc(Reader *input);
  void _skillIdFunc(Reader *input);
  void _skillEndTimeFunc(Reader *input);
};

#endif // HUMANOPTIONSKILLUSE_H