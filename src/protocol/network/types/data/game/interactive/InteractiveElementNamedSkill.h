#ifndef INTERACTIVEELEMENTNAMEDSKILL_H
#define INTERACTIVEELEMENTNAMEDSKILL_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/interactive/InteractiveElementSkill.h"
#include "src/engines/io/network/utils/FuncTree.h"

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