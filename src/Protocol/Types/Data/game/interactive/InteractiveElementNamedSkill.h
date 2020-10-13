#ifndef INTERACTIVEELEMENTNAMEDSKILL_H
#define INTERACTIVEELEMENTNAMEDSKILL_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/interactive/InteractiveElementSkill.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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