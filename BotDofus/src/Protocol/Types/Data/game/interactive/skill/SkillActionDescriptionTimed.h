#ifndef SKILLACTIONDESCRIPTIONTIMED_H
#define SKILLACTIONDESCRIPTIONTIMED_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/interactive/skill/SkillActionDescription.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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