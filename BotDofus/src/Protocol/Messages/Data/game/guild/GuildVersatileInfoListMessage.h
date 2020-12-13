#ifndef GUILDVERSATILEINFOLISTMESSAGE_H
#define GUILDVERSATILEINFOLISTMESSAGE_H

#include "src/protocol/types/data/game/social/GuildVersatileInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildVersatileInfoListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildVersatileInfoListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildVersatileInfoListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildVersatileInfoListMessage(FuncTree tree);
  GuildVersatileInfoListMessage();

  QList<QSharedPointer<GuildVersatileInformations>> guilds;

private:
  void _guildstreeFunc(Reader *input);
  void _guildsFunc(Reader *input);

  FuncTree _guildstree;
};

#endif // GUILDVERSATILEINFOLISTMESSAGE_H