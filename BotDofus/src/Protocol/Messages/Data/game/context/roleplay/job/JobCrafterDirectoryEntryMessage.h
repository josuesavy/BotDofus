#ifndef JOBCRAFTERDIRECTORYENTRYMESSAGE_H
#define JOBCRAFTERDIRECTORYENTRYMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/job/JobCrafterDirectoryEntryPlayerInfo.h"
#include "src/Protocol/Types/Data/game/context/roleplay/job/JobCrafterDirectoryEntryJobInfo.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class JobCrafterDirectoryEntryMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryEntryMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryEntryMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryEntryMessage(FuncTree tree);
  JobCrafterDirectoryEntryMessage();

  QSharedPointer<JobCrafterDirectoryEntryPlayerInfo> playerInfo;
  QList<JobCrafterDirectoryEntryJobInfo> jobInfoList;
  QSharedPointer<EntityLook> playerLook;

private:
  void _playerInfotreeFunc(Reader *input);
  void _jobInfoListtreeFunc(Reader *input);
  void _jobInfoListFunc(Reader *input);
  void _playerLooktreeFunc(Reader *input);

  FuncTree _playerInfotree;
  FuncTree _jobInfoListtree;
  FuncTree _playerLooktree;
};

#endif // JOBCRAFTERDIRECTORYENTRYMESSAGE_H