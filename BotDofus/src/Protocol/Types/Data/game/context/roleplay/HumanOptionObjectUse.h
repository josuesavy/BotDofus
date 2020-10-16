#ifndef HUMANOPTIONOBJECTUSE_H
#define HUMANOPTIONOBJECTUSE_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOption.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class HumanOptionObjectUse : public HumanOption
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanOptionObjectUse(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanOptionObjectUse(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanOptionObjectUse(FuncTree tree);
  HumanOptionObjectUse();
  bool operator==(const HumanOptionObjectUse &compared);

  uint delayTypeId;
  double delayEndTime;
  uint objectGID;

private:
  void _delayTypeIdFunc(Reader *input);
  void _delayEndTimeFunc(Reader *input);
  void _objectGIDFunc(Reader *input);
};

#endif // HUMANOPTIONOBJECTUSE_H