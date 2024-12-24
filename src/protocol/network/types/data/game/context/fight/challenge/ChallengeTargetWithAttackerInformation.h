#ifndef CHALLENGETARGETWITHATTACKERINFORMATION_H
#define CHALLENGETARGETWITHATTACKERINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/fight/challenge/ChallengeTargetInformation.h"
#include "src/utils/io/type/FuncTree.h"

class ChallengeTargetWithAttackerInformation : public ChallengeTargetInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeTargetWithAttackerInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeTargetWithAttackerInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeTargetWithAttackerInformation(FuncTree tree);
  ChallengeTargetWithAttackerInformation();
  bool operator==(const ChallengeTargetWithAttackerInformation &compared);

  QList<double> attackersIds;

private:
  void _attackersIdstreeFunc(Reader *input);
  void _attackersIdsFunc(Reader *input);

  FuncTree _attackersIdstree;
};

#endif // CHALLENGETARGETWITHATTACKERINFORMATION_H