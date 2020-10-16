#ifndef SERVEREXPERIENCEMODIFICATORMESSAGE_H
#define SERVEREXPERIENCEMODIFICATORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ServerExperienceModificatorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServerExperienceModificatorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServerExperienceModificatorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServerExperienceModificatorMessage(FuncTree tree);
  ServerExperienceModificatorMessage();

  uint experiencePercent;

private:
  void _experiencePercentFunc(Reader *input);
};

#endif // SERVEREXPERIENCEMODIFICATORMESSAGE_H