#ifndef JOBCRAFTERDIRECTORYENTRYMESSAGE_H
#define JOBCRAFTERDIRECTORYENTRYMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/job/JobCrafterDirectoryEntryJobInfo.h"
#include "src/protocol/network/types/data/game/context/roleplay/job/JobCrafterDirectoryEntryPlayerInfo.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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