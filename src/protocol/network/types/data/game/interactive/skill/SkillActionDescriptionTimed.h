#ifndef SKILLACTIONDESCRIPTIONTIMED_H
#define SKILLACTIONDESCRIPTIONTIMED_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/interactive/skill/SkillActionDescription.h"
#include "src/utils/io/type/FuncTree.h"

class SkillActionDescriptionTimed : public SkillActionDescription
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SkillActionDescriptionTimed(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SkillActionDescriptionTimed(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SkillActionDescriptionTimed(FuncTree tree);
  SkillActionDescriptionTimed();
  bool operator==(const SkillActionDescriptionTimed &compared);

  uint time;

private:
  void _timeFunc(Reader *input);
};

#endif // SKILLACTIONDESCRIPTIONTIMED_H