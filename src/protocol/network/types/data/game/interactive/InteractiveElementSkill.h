#ifndef INTERACTIVEELEMENTSKILL_H
#define INTERACTIVEELEMENTSKILL_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class InteractiveElementSkill : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InteractiveElementSkill(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InteractiveElementSkill(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InteractiveElementSkill(FuncTree tree);
  InteractiveElementSkill();
  bool operator==(const InteractiveElementSkill &compared);

  uint skillId;
  uint skillInstanceUid;

private:
  void _skillIdFunc(Reader *input);
  void _skillInstanceUidFunc(Reader *input);
};

#endif // INTERACTIVEELEMENTSKILL_H