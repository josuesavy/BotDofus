#ifndef GUILDINFORMATIONSMEMBERSMESSAGE_H
#define GUILDINFORMATIONSMEMBERSMESSAGE_H

#include "src/protocol/network/types/data/game/guild/GuildMemberInfo.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildInformationsMembersMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInformationsMembersMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInformationsMembersMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInformationsMembersMessage(FuncTree tree);
  GuildInformationsMembersMessage();

  QList<QSharedPointer<GuildMemberInfo>> members;

private:
  void _memberstreeFunc(Reader *input);
  void _membersFunc(Reader *input);

  FuncTree _memberstree;
};

#endif // GUILDINFORMATIONSMEMBERSMESSAGE_H