#ifndef JOBCRAFTERDIRECTORYADDMESSAGE_H
#define JOBCRAFTERDIRECTORYADDMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/job/JobCrafterDirectoryListEntry.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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