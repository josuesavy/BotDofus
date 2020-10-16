#ifndef EDITHAVENBAGCANCELREQUESTMESSAGE_H
#define EDITHAVENBAGCANCELREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class EditHavenBagCancelRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EditHavenBagCancelRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EditHavenBagCancelRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EditHavenBagCancelRequestMessage(FuncTree tree);
  EditHavenBagCancelRequestMessage();
};

#endif // EDITHAVENBAGCANCELREQUESTMESSAGE_H