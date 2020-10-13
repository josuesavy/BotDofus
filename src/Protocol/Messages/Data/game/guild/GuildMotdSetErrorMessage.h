#ifndef GUILDMOTDSETERRORMESSAGE_H
#define GUILDMOTDSETERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/social/SocialNoticeSetErrorMessage.h"

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