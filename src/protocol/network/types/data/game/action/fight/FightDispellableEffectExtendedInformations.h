#ifndef FIGHTDISPELLABLEEFFECTEXTENDEDINFORMATIONS_H
#define FIGHTDISPELLABLEEFFECTEXTENDEDINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class FightDispellableEffectExtendedInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightDispellableEffectExtendedInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightDispellableEffectExtendedInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightDispellableEffectExtendedInformations(FuncTree tree);
  FightDispellableEffectExtendedInformations();
  bool operator==(const FightDispellableEffectExtendedInformations &compared);

  uint actionId;
  double sourceId;
  QSharedPointer<AbstractFightDispellableEffect> effect;

private:
  void _actionIdFunc(Reader *input);
  void _sourceIdFunc(Reader *input);
  void _effecttreeFunc(Reader *input);

  FuncTree _effecttree;
};

#endif // FIGHTDISPELLABLEEFFECTEXTENDEDINFORMATIONS_H