#ifndef GUIDEDMODEQUITREQUESTMESSAGE_H
#define GUIDEDMODEQUITREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuidedModeQuitRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuidedModeQuitRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuidedModeQuitRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuidedModeQuitRequestMessage(FuncTree tree);
  GuidedModeQuitRequestMessage();
};

#endif // GUIDEDMODEQUITREQUESTMESSAGE_H