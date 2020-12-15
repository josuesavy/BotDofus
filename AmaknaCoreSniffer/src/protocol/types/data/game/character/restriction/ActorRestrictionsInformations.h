#ifndef ACTORRESTRICTIONSINFORMATIONS_H
#define ACTORRESTRICTIONSINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ActorRestrictionsInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ActorRestrictionsInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ActorRestrictionsInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ActorRestrictionsInformations(FuncTree tree);
  ActorRestrictionsInformations();
  bool operator==(const ActorRestrictionsInformations &compared);

  bool cantBeAggressed;
  bool cantBeChallenged;
  bool cantTrade;
  bool cantBeAttackedByMutant;
  bool cantRun;
  bool forceSlowWalk;
  bool cantMinimize;
  bool cantMove;
  bool cantAggress;
  bool cantChallenge;
  bool cantExchange;
  bool cantAttack;
  bool cantChat;
  bool cantBeMerchant;
  bool cantUseObject;
  bool cantUseTaxCollector;
  bool cantUseInteractive;
  bool cantSpeakToNPC;
  bool cantChangeZone;
  bool cantAttackMonster;
  bool cantWalk8Directions;

private:
  void deserializeByteBoxes(Reader *input);
};

#endif // ACTORRESTRICTIONSINFORMATIONS_H