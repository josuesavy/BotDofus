#ifndef ONCONNECTIONEVENTMESSAGE_H
#define ONCONNECTIONEVENTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class OnConnectionEventMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_OnConnectionEventMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_OnConnectionEventMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_OnConnectionEventMessage(FuncTree tree);
  OnConnectionEventMessage();

  uint eventType;

private:
  void _eventTypeFunc(Reader *input);
};

#endif // ONCONNECTIONEVENTMESSAGE_H