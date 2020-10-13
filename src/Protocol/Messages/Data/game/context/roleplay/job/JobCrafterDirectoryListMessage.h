#ifndef JOBCRAFTERDIRECTORYLISTMESSAGE_H
#define JOBCRAFTERDIRECTORYLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/job/JobCrafterDirectoryListEntry.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class JobCrafterDirectoryListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryListMessage(FuncTree tree);
  JobCrafterDirectoryListMessage();

  QList<QSharedPointer<JobCrafterDirectoryListEntry>> listEntries;

private:
  void _listEntriestreeFunc(Reader *input);
  void _listEntriesFunc(Reader *input);

  FuncTree _listEntriestree;
};

#endif // JOBCRAFTERDIRECTORYLISTMESSAGE_H