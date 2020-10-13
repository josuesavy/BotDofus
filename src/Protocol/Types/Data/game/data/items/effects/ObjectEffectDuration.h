#ifndef OBJECTEFFECTDURATION_H
#define OBJECTEFFECTDURATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/data/items/effects/ObjectEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ObjectEffectDuration : public ObjectEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectEffectDuration(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectEffectDuration(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectEffectDuration(FuncTree tree);
  ObjectEffectDuration();
  bool operator==(const ObjectEffectDuration &compared);

  uint days;
  uint hours;
  uint minutes;

private:
  void _daysFunc(Reader *input);
  void _hoursFunc(Reader *input);
  void _minutesFunc(Reader *input);
};

#endif // OBJECTEFFECTDURATION_H