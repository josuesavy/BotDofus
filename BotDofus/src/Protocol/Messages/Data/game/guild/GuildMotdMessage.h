#ifndef GUILDMOTDMESSAGE_H
#define GUILDMOTDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/social/SocialNoticeMessage.h"

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