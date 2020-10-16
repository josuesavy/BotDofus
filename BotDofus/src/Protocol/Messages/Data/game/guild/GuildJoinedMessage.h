#ifndef GUILDJOINEDMESSAGE_H
#define GUILDJOINEDMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
  uint memberRights;

private:
  void _guildInfotreeFunc(Reader *input);
  void _memberRightsFunc(Reader *input);

  FuncTree _guildInfotree;
};

#endif // GUILDJOINEDMESSAGE_H