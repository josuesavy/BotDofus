#ifndef JOBEXPERIENCE_H
#define JOBEXPERIENCE_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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