#ifndef CHALLENGETARGETINFORMATION_H
#define CHALLENGETARGETINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class ChallengeTargetInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChallengeTargetInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChallengeTargetInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChallengeTargetInformation(FuncTree tree);
  ChallengeTargetInformation();
  bool operator==(const ChallengeTargetInformation &compared);

  double targetId;
  int targetCell;

private:
  void _targetIdFunc(Reader *input);
  void _targetCellFunc(Reader *input);
};

#endif // CHALLENGETARGETINFORMATION_H