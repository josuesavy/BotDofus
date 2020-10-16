#ifndef GUILDMOTDSETREQUESTMESSAGE_H
#define GUILDMOTDSETREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/social/SocialNoticeSetRequestMessage.h"

class GuildMotdSetRequestMessage : public SocialNoticeSetRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMotdSetRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMotdSetRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMotdSetRequestMessage(FuncTree tree);
  GuildMotdSetRequestMessage();

  QString content;

private:
  void _contentFunc(Reader *input);
};

#endif // GUILDMOTDSETREQUESTMESSAGE_H