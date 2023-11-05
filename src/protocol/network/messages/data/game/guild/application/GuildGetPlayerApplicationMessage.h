#ifndef GUILDGETPLAYERAPPLICATIONMESSAGE_H
#define GUILDGETPLAYERAPPLICATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildGetPlayerApplicationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildGetPlayerApplicationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildGetPlayerApplicationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildGetPlayerApplicationMessage(FuncTree tree);
  GuildGetPlayerApplicationMessage();
};

#endif // GUILDGETPLAYERAPPLICATIONMESSAGE_H