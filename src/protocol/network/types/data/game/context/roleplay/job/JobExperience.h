#ifndef JOBEXPERIENCE_H
#define JOBEXPERIENCE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class JobExperience : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobExperience(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobExperience(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobExperience(FuncTree tree);
  JobExperience();
  bool operator==(const JobExperience &compared);

  uint jobId;
  uint jobLevel;
  double jobXP;
  double jobXpLevelFloor;
  double jobXpNextLevelFloor;

private:
  void _jobIdFunc(Reader *input);
  void _jobLevelFunc(Reader *input);
  void _jobXPFunc(Reader *input);
  void _jobXpLevelFloorFunc(Reader *input);
  void _jobXpNextLevelFloorFunc(Reader *input);
};

#endif // JOBEXPERIENCE_H