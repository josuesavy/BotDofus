#ifndef CHALLENGEINFORMATION_H
#define CHALLENGEINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/fight/challenge/ChallengeTargetInformation.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class ChallengeInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeInformation(FuncTree tree);
  ChallengeInformation();
  bool operator==(const ChallengeInformation &compared);

  uint challengeId;
  QList<QSharedPointer<ChallengeTargetInformation>> targetsList;
  uint dropBonus;
  uint xpBonus;
  uint state;

private:
  void _challengeIdFunc(Reader *input);
  void _targetsListtreeFunc(Reader *input);
  void _targetsListFunc(Reader *input);
  void _dropBonusFunc(Reader *input);
  void _xpBonusFunc(Reader *input);
  void _stateFunc(Reader *input);

  FuncTree _targetsListtree;
};

#endif // CHALLENGEINFORMATION_H