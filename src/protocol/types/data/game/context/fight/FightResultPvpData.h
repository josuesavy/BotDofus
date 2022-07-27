#ifndef FIGHTRESULTPVPDATA_H
#define FIGHTRESULTPVPDATA_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/FightResultAdditionalData.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightResultPvpData : public FightResultAdditionalData
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightResultPvpData(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightResultPvpData(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightResultPvpData(FuncTree tree);
  FightResultPvpData();
  bool operator==(const FightResultPvpData &compared);

  uint grade;
  uint minHonorForGrade;
  uint maxHonorForGrade;
  uint honor;
  int honorDelta;

private:
  void _gradeFunc(Reader *input);
  void _minHonorForGradeFunc(Reader *input);
  void _maxHonorForGradeFunc(Reader *input);
  void _honorFunc(Reader *input);
  void _honorDeltaFunc(Reader *input);
};

#endif // FIGHTRESULTPVPDATA_H