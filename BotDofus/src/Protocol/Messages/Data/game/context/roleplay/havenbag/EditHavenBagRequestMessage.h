#ifndef EDITHAVENBAGREQUESTMESSAGE_H
#define EDITHAVENBAGREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class EditHavenBagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EditHavenBagRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EditHavenBagRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EditHavenBagRequestMessage(FuncTree tree);
  EditHavenBagRequestMessage();
};

#endif // EDITHAVENBAGREQUESTMESSAGE_H