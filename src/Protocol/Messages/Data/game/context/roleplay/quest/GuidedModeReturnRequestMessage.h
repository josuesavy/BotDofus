#ifndef GUIDEDMODERETURNREQUESTMESSAGE_H
#define GUIDEDMODERETURNREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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