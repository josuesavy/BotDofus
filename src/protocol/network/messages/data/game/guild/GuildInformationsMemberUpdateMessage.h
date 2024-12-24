#ifndef GUILDINFORMATIONSMEMBERUPDATEMESSAGE_H
#define GUILDINFORMATIONSMEMBERUPDATEMESSAGE_H

#include "src/protocol/network/types/data/game/guild/GuildMemberInfo.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  QSharedPointer<GuildMemberInfo> member;

private:
  void _membertreeFunc(Reader *input);

  FuncTree _membertree;
};

#endif // GUILDINFORMATIONSMEMBERUPDATEMESSAGE_H