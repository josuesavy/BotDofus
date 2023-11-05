#ifndef FIGHTPHASE_H
#define FIGHTPHASE_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightPhase : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightPhase(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightPhase(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightPhase(FuncTree tree);
  FightPhase();
  bool operator==(const FightPhase &compared);

  uint phase;
  double phaseEndTimeStamp;

private:
  void _phaseFunc(Reader *input);
  void _phaseEndTimeStampFunc(Reader *input);
};

#endif // FIGHTPHASE_H