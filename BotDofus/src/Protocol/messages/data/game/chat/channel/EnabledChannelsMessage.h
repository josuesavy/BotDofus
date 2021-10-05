#ifndef ENABLEDCHANNELSMESSAGE_H
#define ENABLEDCHANNELSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class EnabledChannelsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EnabledChannelsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EnabledChannelsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EnabledChannelsMessage(FuncTree tree);
  EnabledChannelsMessage();

  QList<uint> channels;
  QList<uint> disallowed;

private:
  void _channelstreeFunc(Reader *input);
  void _channelsFunc(Reader *input);
  void _disallowedtreeFunc(Reader *input);
  void _disallowedFunc(Reader *input);

  FuncTree _channelstree;
  FuncTree _disallowedtree;
};

#endif // ENABLEDCHANNELSMESSAGE_H