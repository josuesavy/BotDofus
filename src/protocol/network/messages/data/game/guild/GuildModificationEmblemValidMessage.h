#ifndef GUILDMODIFICATIONEMBLEMVALIDMESSAGE_H
#define GUILDMODIFICATIONEMBLEMVALIDMESSAGE_H

#include "src/protocol/types/data/game/social/SocialEmblem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildModificationEmblemValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildModificationEmblemValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildModificationEmblemValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildModificationEmblemValidMessage(FuncTree tree);
  GuildModificationEmblemValidMessage();

  SocialEmblem guildEmblem;

private:
  void _guildEmblemtreeFunc(Reader *input);

  FuncTree _guildEmblemtree;
};

#endif // GUILDMODIFICATIONEMBLEMVALIDMESSAGE_H