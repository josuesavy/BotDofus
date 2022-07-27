#ifndef GUILDPLAYERAPPLICATIONABSTRACTMESSAGE_H
#define GUILDPLAYERAPPLICATIONABSTRACTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildPlayerApplicationAbstractMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildPlayerApplicationAbstractMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildPlayerApplicationAbstractMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildPlayerApplicationAbstractMessage(FuncTree tree);
  GuildPlayerApplicationAbstractMessage();
};

#endif // GUILDPLAYERAPPLICATIONABSTRACTMESSAGE_H