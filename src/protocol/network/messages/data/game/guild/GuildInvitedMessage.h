#ifndef GUILDINVITEDMESSAGE_H
#define GUILDINVITEDMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/GuildInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildInvitedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInvitedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInvitedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInvitedMessage(FuncTree tree);
  GuildInvitedMessage();

  QString recruterName;
  QSharedPointer<GuildInformations> guildInfo;

private:
  void _recruterNameFunc(Reader *input);
  void _guildInfotreeFunc(Reader *input);

  FuncTree _guildInfotree;
};

#endif // GUILDINVITEDMESSAGE_H