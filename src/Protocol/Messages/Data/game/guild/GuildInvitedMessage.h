#ifndef GUILDINVITEDMESSAGE_H
#define GUILDINVITEDMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/BasicGuildInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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

  double recruterId;
  QString recruterName;
  QSharedPointer<BasicGuildInformations> guildInfo;

private:
  void _recruterIdFunc(Reader *input);
  void _recruterNameFunc(Reader *input);
  void _guildInfotreeFunc(Reader *input);

  FuncTree _guildInfotree;
};

#endif // GUILDINVITEDMESSAGE_H