#ifndef GUILDMOTDMESSAGE_H
#define GUILDMOTDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/social/SocialNoticeMessage.h"

class GuildMotdMessage : public SocialNoticeMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMotdMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMotdMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMotdMessage(FuncTree tree);
  GuildMotdMessage();
};

#endif // GUILDMOTDMESSAGE_H