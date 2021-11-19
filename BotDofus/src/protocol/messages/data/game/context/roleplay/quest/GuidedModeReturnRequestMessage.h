#ifndef GUIDEDMODERETURNREQUESTMESSAGE_H
#define GUIDEDMODERETURNREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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