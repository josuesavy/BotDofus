#ifndef JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE_H
#define JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/job/JobCrafterDirectorySettings.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class JobCrafterDirectoryDefineSettingsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_JobCrafterDirectoryDefineSettingsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_JobCrafterDirectoryDefineSettingsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_JobCrafterDirectoryDefineSettingsMessage(FuncTree tree);
  JobCrafterDirectoryDefineSettingsMessage();

  JobCrafterDirectorySettings settings;

private:
  void _settingstreeFunc(Reader *input);

  FuncTree _settingstree;
};

#endif // JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE_H