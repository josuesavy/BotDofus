#ifndef GUILDJOINEDMESSAGE_H
#define GUILDJOINEDMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildJoinedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildJoinedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildJoinedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildJoinedMessage(FuncTree tree);
  GuildJoinedMessage();

  QSharedPointer<GuildInformations> guildInfo;
  uint rankId;

private:
  void _guildInfotreeFunc(Reader *input);
  void _rankIdFunc(Reader *input);

  FuncTree _guildInfotree;
};

#endif // GUILDJOINEDMESSAGE_H