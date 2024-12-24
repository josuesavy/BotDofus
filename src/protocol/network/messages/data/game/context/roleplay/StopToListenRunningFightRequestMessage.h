#ifndef STOPTOLISTENRUNNINGFIGHTREQUESTMESSAGE_H
#define STOPTOLISTENRUNNINGFIGHTREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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