#ifndef INTERACTIVEELEMENTNAMEDSKILL_H
#define INTERACTIVEELEMENTNAMEDSKILL_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/interactive/InteractiveElementSkill.h"
#include "src/utils/io/type/FuncTree.h"

class InteractiveElementNamedSkill : public InteractiveElementSkill
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InteractiveElementNamedSkill(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InteractiveElementNamedSkill(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InteractiveElementNamedSkill(FuncTree tree);
  InteractiveElementNamedSkill();
  bool operator==(const InteractiveElementNamedSkill &compared);

  uint nameId;

private:
  void _nameIdFunc(Reader *input);
};

#endif // INTERACTIVEELEMENTNAMEDSKILL_H