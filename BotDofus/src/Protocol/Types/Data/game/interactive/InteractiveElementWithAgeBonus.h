#ifndef INTERACTIVEELEMENTWITHAGEBONUS_H
#define INTERACTIVEELEMENTWITHAGEBONUS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/interactive/InteractiveElement.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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