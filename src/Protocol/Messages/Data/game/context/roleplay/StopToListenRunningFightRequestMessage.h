#ifndef STOPTOLISTENRUNNINGFIGHTREQUESTMESSAGE_H
#define STOPTOLISTENRUNNINGFIGHTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class StopToListenRunningFightRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StopToListenRunningFightRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StopToListenRunningFightRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StopToListenRunningFightRequestMessage(FuncTree tree);
  StopToListenRunningFightRequestMessage();
};

#endif // STOPTOLISTENRUNNINGFIGHTREQUESTMESSAGE_H