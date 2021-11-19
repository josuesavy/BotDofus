#ifndef GAMEFIGHTEFFECTTRIGGERCOUNT_H
#define GAMEFIGHTEFFECTTRIGGERCOUNT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameFightEffectTriggerCount : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightEffectTriggerCount(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightEffectTriggerCount(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightEffectTriggerCount(FuncTree tree);
  GameFightEffectTriggerCount();
  bool operator==(const GameFightEffectTriggerCount &compared);

  uint effectId;
  double targetId;
  uint count;

private:
  void _effectIdFunc(Reader *input);
  void _targetIdFunc(Reader *input);
  void _countFunc(Reader *input);
};

#endif // GAMEFIGHTEFFECTTRIGGERCOUNT_H