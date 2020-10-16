#ifndef OBJECTEFFECTDATE_H
#define OBJECTEFFECTDATE_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectEffectDate : public ObjectEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectEffectDate(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectEffectDate(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectEffectDate(FuncTree tree);
  ObjectEffectDate();
  bool operator==(const ObjectEffectDate &compared);

  uint year;
  uint month;
  uint day;
  uint hour;
  uint minute;

private:
  void _yearFunc(Reader *input);
  void _monthFunc(Reader *input);
  void _dayFunc(Reader *input);
  void _hourFunc(Reader *input);
  void _minuteFunc(Reader *input);
};

#endif // OBJECTEFFECTDATE_H