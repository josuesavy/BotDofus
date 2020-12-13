#ifndef GUILDMODIFICATIONVALIDMESSAGE_H
#define GUILDMODIFICATIONVALIDMESSAGE_H

#include "src/protocol/types/data/game/guild/GuildEmblem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildModificationValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildModificationValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildModificationValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildModificationValidMessage(FuncTree tree);
  GuildModificationValidMessage();

  QString guildName;
  GuildEmblem guildEmblem;

private:
  void _guildNameFunc(Reader *input);
  void _guildEmblemtreeFunc(Reader *input);

  FuncTree _guildEmblemtree;
};

#endif // GUILDMODIFICATIONVALIDMESSAGE_H