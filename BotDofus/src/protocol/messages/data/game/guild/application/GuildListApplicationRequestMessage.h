#ifndef GUILDLISTAPPLICATIONREQUESTMESSAGE_H
#define GUILDLISTAPPLICATIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/PaginationRequestAbstractMessage.h"

class GuildListApplicationRequestMessage : public PaginationRequestAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildListApplicationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildListApplicationRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildListApplicationRequestMessage(FuncTree tree);
  GuildListApplicationRequestMessage();
};

#endif // GUILDLISTAPPLICATIONREQUESTMESSAGE_H