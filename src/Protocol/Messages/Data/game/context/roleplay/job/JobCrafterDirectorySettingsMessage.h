#ifndef JOBCRAFTERDIRECTORYSETTINGSMESSAGE_H
#define JOBCRAFTERDIRECTORYSETTINGSMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/job/JobCrafterDirectorySettings.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class JobCrafterDirectorySettingsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectorySettingsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectorySettingsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectorySettingsMessage(FuncTree tree);
  JobCrafterDirectorySettingsMessage();

  QList<JobCrafterDirectorySettings> craftersSettings;

private:
  void _craftersSettingstreeFunc(Reader *input);
  void _craftersSettingsFunc(Reader *input);

  FuncTree _craftersSettingstree;
};

#endif // JOBCRAFTERDIRECTORYSETTINGSMESSAGE_H