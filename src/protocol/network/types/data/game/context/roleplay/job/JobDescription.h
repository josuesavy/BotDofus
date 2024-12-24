#ifndef JOBDESCRIPTION_H
#define JOBDESCRIPTION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/interactive/skill/SkillActionDescription.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class JobDescription : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobDescription(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobDescription(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobDescription(FuncTree tree);
  JobDescription();
  bool operator==(const JobDescription &compared);

  uint jobId;
  QList<QSharedPointer<SkillActionDescription>> skills;

private:
  void _jobIdFunc(Reader *input);
  void _skillstreeFunc(Reader *input);
  void _skillsFunc(Reader *input);

  FuncTree _skillstree;
};

#endif // JOBDESCRIPTION_H