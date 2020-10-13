#ifndef JOBCRAFTERDIRECTORYLISTENTRY_H
#define JOBCRAFTERDIRECTORYLISTENTRY_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/job/JobCrafterDirectoryEntryPlayerInfo.h"
#include "src/Protocol/Types/Data/game/context/roleplay/job/JobCrafterDirectoryEntryJobInfo.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class JobCrafterDirectoryListEntry : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryListEntry(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryListEntry(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryListEntry(FuncTree tree);
  JobCrafterDirectoryListEntry();
  bool operator==(const JobCrafterDirectoryListEntry &compared);

  QSharedPointer<JobCrafterDirectoryEntryPlayerInfo> playerInfo;
  JobCrafterDirectoryEntryJobInfo jobInfo;

private:
  void _playerInfotreeFunc(Reader *input);
  void _jobInfotreeFunc(Reader *input);

  FuncTree _playerInfotree;
  FuncTree _jobInfotree;
};

#endif // JOBCRAFTERDIRECTORYLISTENTRY_H