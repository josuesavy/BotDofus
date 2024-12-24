#ifndef JOBCRAFTERDIRECTORYENTRYJOBINFO_H
#define JOBCRAFTERDIRECTORYENTRYJOBINFO_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class JobCrafterDirectoryEntryJobInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryEntryJobInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryEntryJobInfo(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryEntryJobInfo(FuncTree tree);
  JobCrafterDirectoryEntryJobInfo();
  bool operator==(const JobCrafterDirectoryEntryJobInfo &compared);

  uint jobId;
  uint jobLevel;
  bool free;
  uint minLevel;

private:
  void _jobIdFunc(Reader *input);
  void _jobLevelFunc(Reader *input);
  void _freeFunc(Reader *input);
  void _minLevelFunc(Reader *input);
};

#endif // JOBCRAFTERDIRECTORYENTRYJOBINFO_H