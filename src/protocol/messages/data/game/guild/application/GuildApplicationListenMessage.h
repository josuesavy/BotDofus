#ifndef GUILDAPPLICATIONLISTENMESSAGE_H
#define GUILDAPPLICATIONLISTENMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildApplicationListenMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildApplicationListenMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildApplicationListenMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildApplicationListenMessage(FuncTree tree);
  GuildApplicationListenMessage();

  bool listen;

private:
  void _listenFunc(Reader *input);
};

#endif // GUILDAPPLICATIONLISTENMESSAGE_H