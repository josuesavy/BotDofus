#ifndef FIGHTTRIGGEREDEFFECT_H
#define FIGHTTRIGGEREDEFFECT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightTriggeredEffect : public AbstractFightDispellableEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTriggeredEffect(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTriggeredEffect(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTriggeredEffect(FuncTree tree);
  FightTriggeredEffect();
  bool operator==(const FightTriggeredEffect &compared);

  int param1;
  int param2;
  int param3;
  int delay;

private:
  void _param1Func(Reader *input);
  void _param2Func(Reader *input);
  void _param3Func(Reader *input);
  void _delayFunc(Reader *input);
};

#endif // FIGHTTRIGGEREDEFFECT_H