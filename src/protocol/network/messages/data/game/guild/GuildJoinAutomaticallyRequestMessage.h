#ifndef GUILDJOINAUTOMATICALLYREQUESTMESSAGE_H
#define GUILDJOINAUTOMATICALLYREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildJoinAutomaticallyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildJoinAutomaticallyRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildJoinAutomaticallyRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildJoinAutomaticallyRequestMessage(FuncTree tree);
  GuildJoinAutomaticallyRequestMessage();

  int guildId;

private:
  void _guildIdFunc(Reader *input);
};

#endif // GUILDJOINAUTOMATICALLYREQUESTMESSAGE_H