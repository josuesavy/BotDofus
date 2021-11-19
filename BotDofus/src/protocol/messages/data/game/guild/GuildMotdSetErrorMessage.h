#ifndef GUILDMOTDSETERRORMESSAGE_H
#define GUILDMOTDSETERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/social/SocialNoticeSetErrorMessage.h"

class GuildMotdSetErrorMessage : public SocialNoticeSetErrorMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMotdSetErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMotdSetErrorMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMotdSetErrorMessage(FuncTree tree);
  GuildMotdSetErrorMessage();
};

#endif // GUILDMOTDSETERRORMESSAGE_H