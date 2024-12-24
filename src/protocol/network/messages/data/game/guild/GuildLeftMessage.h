#ifndef GUILDLEFTMESSAGE_H
#define GUILDLEFTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildLeftMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildLeftMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildLeftMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildLeftMessage(FuncTree tree);
  GuildLeftMessage();
};

#endif // GUILDLEFTMESSAGE_H