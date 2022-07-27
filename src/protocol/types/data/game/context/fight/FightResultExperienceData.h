#ifndef FIGHTRESULTEXPERIENCEDATA_H
#define FIGHTRESULTEXPERIENCEDATA_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/FightResultAdditionalData.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"

class FightResultExperienceData : public FightResultAdditionalData
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FightResultExperienceData(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FightResultExperienceData(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FightResultExperienceData(FuncTree tree);
  FightResultExperienceData();
  bool operator==(const FightResultExperienceData &compared);

  double experience;
  bool showExperience;
  double experienceLevelFloor;
  bool showExperienceLevelFloor;
  double experienceNextLevelFloor;
  bool showExperienceNextLevelFloor;
  double experienceFightDelta;
  bool showExperienceFightDelta;
  double experienceForGuild;
  bool showExperienceForGuild;
  double experienceForMount;
  bool showExperienceForMount;
  bool isIncarnationExperience;
  uint rerollExperienceMul;

private:
  void deserializeByteBoxes(Reader *input);
  void _experienceFunc(Reader *input);
  void _experienceLevelFloorFunc(Reader *input);
  void _experienceNextLevelFloorFunc(Reader *input);
  void _experienceFightDeltaFunc(Reader *input);
  void _experienceForGuildFunc(Reader *input);
  void _experienceForMountFunc(Reader *input);
  void _rerollExperienceMulFunc(Reader *input);
};

#endif // FIGHTRESULTEXPERIENCEDATA_H