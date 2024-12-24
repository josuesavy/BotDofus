#ifndef GUILDRANKSREQUESTMESSAGE_H
#define GUILDRANKSREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildRanksRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildRanksRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildRanksRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildRanksRequestMessage(FuncTree tree);
  GuildRanksRequestMessage();
};

#endif // GUILDRANKSREQUESTMESSAGE_H