#ifndef SKILLACTIONDESCRIPTION_H
#define SKILLACTIONDESCRIPTION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class SkillActionDescription : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SkillActionDescription(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SkillActionDescription(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SkillActionDescription(FuncTree tree);
  SkillActionDescription();
  bool operator==(const SkillActionDescription &compared);

  uint skillId;

private:
  void _skillIdFunc(Reader *input);
};

#endif // SKILLACTIONDESCRIPTION_H