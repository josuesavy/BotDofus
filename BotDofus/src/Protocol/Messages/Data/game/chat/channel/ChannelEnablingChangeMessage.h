#ifndef CHANNELENABLINGCHANGEMESSAGE_H
#define CHANNELENABLINGCHANGEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ChannelEnablingChangeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ChannelEnablingChangeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ChannelEnablingChangeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ChannelEnablingChangeMessage(FuncTree tree);
  ChannelEnablingChangeMessage();

  uint channel;
  bool enable;

private:
  void _channelFunc(Reader *input);
  void _enableFunc(Reader *input);
};

#endif // CHANNELENABLINGCHANGEMESSAGE_H