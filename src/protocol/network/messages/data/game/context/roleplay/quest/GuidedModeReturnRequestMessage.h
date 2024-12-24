#ifndef GUIDEDMODERETURNREQUESTMESSAGE_H
#define GUIDEDMODERETURNREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuidedModeReturnRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuidedModeReturnRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuidedModeReturnRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuidedModeReturnRequestMessage(FuncTree tree);
  GuidedModeReturnRequestMessage();
};

#endif // GUIDEDMODERETURNREQUESTMESSAGE_H