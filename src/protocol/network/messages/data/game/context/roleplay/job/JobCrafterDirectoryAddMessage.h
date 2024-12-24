#ifndef JOBCRAFTERDIRECTORYADDMESSAGE_H
#define JOBCRAFTERDIRECTORYADDMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/job/JobCrafterDirectoryListEntry.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class JobCrafterDirectoryAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryAddMessage(FuncTree tree);
  JobCrafterDirectoryAddMessage();

  QSharedPointer<JobCrafterDirectoryListEntry> listEntry;

private:
  void _listEntrytreeFunc(Reader *input);

  FuncTree _listEntrytree;
};

#endif // JOBCRAFTERDIRECTORYADDMESSAGE_H