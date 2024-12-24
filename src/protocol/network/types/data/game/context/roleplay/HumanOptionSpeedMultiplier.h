#ifndef HUMANOPTIONSPEEDMULTIPLIER_H
#define HUMANOPTIONSPEEDMULTIPLIER_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/HumanOption.h"
#include "src/utils/io/type/FuncTree.h"

class HumanOptionSpeedMultiplier : public HumanOption
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanOptionSpeedMultiplier(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanOptionSpeedMultiplier(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanOptionSpeedMultiplier(FuncTree tree);
  HumanOptionSpeedMultiplier();
  bool operator==(const HumanOptionSpeedMultiplier &compared);

  uint speedMultiplier;

private:
  void _speedMultiplierFunc(Reader *input);
};

#endif // HUMANOPTIONSPEEDMULTIPLIER_H