#ifndef SKILLACTIONDESCRIPTIONCRAFT_H
#define SKILLACTIONDESCRIPTIONCRAFT_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/interactive/skill/SkillActionDescription.h"
#include "src/utils/io/type/FuncTree.h"

class SkillActionDescriptionCraft : public SkillActionDescription
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SkillActionDescriptionCraft(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SkillActionDescriptionCraft(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SkillActionDescriptionCraft(FuncTree tree);
  SkillActionDescriptionCraft();
  bool operator==(const SkillActionDescriptionCraft &compared);

  uint probability;

private:
  void _probabilityFunc(Reader *input);
};

#endif // SKILLACTIONDESCRIPTIONCRAFT_H