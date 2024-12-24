#ifndef SKILLACTIONDESCRIPTIONCOLLECT_H
#define SKILLACTIONDESCRIPTIONCOLLECT_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/interactive/skill/SkillActionDescriptionTimed.h"
#include "src/utils/io/type/FuncTree.h"

class SkillActionDescriptionCollect : public SkillActionDescriptionTimed
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SkillActionDescriptionCollect(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SkillActionDescriptionCollect(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SkillActionDescriptionCollect(FuncTree tree);
  SkillActionDescriptionCollect();
  bool operator==(const SkillActionDescriptionCollect &compared);

  uint min;
  uint max;

private:
  void _minFunc(Reader *input);
  void _maxFunc(Reader *input);
};

#endif // SKILLACTIONDESCRIPTIONCOLLECT_H