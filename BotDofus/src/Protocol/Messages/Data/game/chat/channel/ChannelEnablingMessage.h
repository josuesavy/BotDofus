#ifndef CHANNELENABLINGMESSAGE_H
#define CHANNELENABLINGMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ChannelEnablingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChannelEnablingMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChannelEnablingMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChannelEnablingMessage(FuncTree tree);
  ChannelEnablingMessage();

  uint channel;
  bool enable;

private:
  void _channelFunc(Reader *input);
  void _enableFunc(Reader *input);
};

#endif // CHANNELENABLINGMESSAGE_H