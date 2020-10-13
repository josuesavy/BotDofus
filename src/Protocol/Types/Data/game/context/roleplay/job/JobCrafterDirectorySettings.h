#ifndef JOBCRAFTERDIRECTORYSETTINGS_H
#define JOBCRAFTERDIRECTORYSETTINGS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class JobCrafterDirectorySettings : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectorySettings(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectorySettings(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectorySettings(FuncTree tree);
  JobCrafterDirectorySettings();
  bool operator==(const JobCrafterDirectorySettings &compared);

  uint jobId;
  uint minLevel;
  bool free;

private:
  void _jobIdFunc(Reader *input);
  void _minLevelFunc(Reader *input);
  void _freeFunc(Reader *input);
};

#endif // JOBCRAFTERDIRECTORYSETTINGS_H