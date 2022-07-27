#ifndef GUILDINFORMATIONSMEMBERUPDATEMESSAGE_H
#define GUILDINFORMATIONSMEMBERUPDATEMESSAGE_H

#include "src/protocol/types/data/game/guild/GuildMember.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildInformationsMemberUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInformationsMemberUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInformationsMemberUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInformationsMemberUpdateMessage(FuncTree tree);
  GuildInformationsMemberUpdateMessage();

  QSharedPointer<GuildMember> member;

private:
  void _membertreeFunc(Reader *input);

  FuncTree _membertree;
};

#endif // GUILDINFORMATIONSMEMBERUPDATEMESSAGE_H