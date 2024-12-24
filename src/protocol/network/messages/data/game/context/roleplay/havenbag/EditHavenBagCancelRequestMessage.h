#ifndef EDITHAVENBAGCANCELREQUESTMESSAGE_H
#define EDITHAVENBAGCANCELREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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