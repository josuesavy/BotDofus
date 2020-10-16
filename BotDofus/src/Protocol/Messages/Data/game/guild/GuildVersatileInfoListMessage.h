#ifndef GUILDVERSATILEINFOLISTMESSAGE_H
#define GUILDVERSATILEINFOLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/social/GuildVersatileInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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