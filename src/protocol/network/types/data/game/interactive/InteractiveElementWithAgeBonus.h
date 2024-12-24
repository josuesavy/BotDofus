#ifndef INTERACTIVEELEMENTWITHAGEBONUS_H
#define INTERACTIVEELEMENTWITHAGEBONUS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/interactive/InteractiveElement.h"
#include "src/utils/io/type/FuncTree.h"

class InteractiveElementWithAgeBonus : public InteractiveElement
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InteractiveElementWithAgeBonus(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InteractiveElementWithAgeBonus(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InteractiveElementWithAgeBonus(FuncTree tree);
  InteractiveElementWithAgeBonus();
  bool operator==(const InteractiveElementWithAgeBonus &compared);

  int ageBonus;

private:
  void _ageBonusFunc(Reader *input);
};

#endif // INTERACTIVEELEMENTWITHAGEBONUS_H