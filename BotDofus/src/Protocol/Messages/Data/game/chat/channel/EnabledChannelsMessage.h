#ifndef ENABLEDCHANNELSMESSAGE_H
#define ENABLEDCHANNELSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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