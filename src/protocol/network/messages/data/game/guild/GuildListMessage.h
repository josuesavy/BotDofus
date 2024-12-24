#ifndef GUILDLISTMESSAGE_H
#define GUILDLISTMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/GuildInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildListMessage(FuncTree tree);
  GuildListMessage();

  QList<QSharedPointer<GuildInformations>> guilds;

private:
  void _guildstreeFunc(Reader *input);
  void _guildsFunc(Reader *input);

  FuncTree _guildstree;
};

#endif // GUILDLISTMESSAGE_H