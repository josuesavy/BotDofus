#ifndef FIGHTTEMPORARYBOOSTEFFECT_H
#define FIGHTTEMPORARYBOOSTEFFECT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class FightTemporaryBoostEffect : public AbstractFightDispellableEffect
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightTemporaryBoostEffect(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightTemporaryBoostEffect(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightTemporaryBoostEffect(FuncTree tree);
  FightTemporaryBoostEffect();
  bool operator==(const FightTemporaryBoostEffect &compared);

  int delta;

private:
  void _deltaFunc(Reader *input);
};

#endif // FIGHTTEMPORARYBOOSTEFFECT_H