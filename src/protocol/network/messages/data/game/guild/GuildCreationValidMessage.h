#ifndef GUILDCREATIONVALIDMESSAGE_H
#define GUILDCREATIONVALIDMESSAGE_H

#include "src/protocol/network/types/data/game/social/SocialEmblem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildCreationValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildCreationValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildCreationValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildCreationValidMessage(FuncTree tree);
  GuildCreationValidMessage();

  QString guildName;
  SocialEmblem guildEmblem;

private:
  void _guildNameFunc(Reader *input);
  void _guildEmblemtreeFunc(Reader *input);

  FuncTree _guildEmblemtree;
};

#endif // GUILDCREATIONVALIDMESSAGE_H