#ifndef GUILDINVITATIONBYNAMEMESSAGE_H
#define GUILDINVITATIONBYNAMEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildInvitationByNameMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInvitationByNameMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInvitationByNameMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInvitationByNameMessage(FuncTree tree);
  GuildInvitationByNameMessage();

  QString name;

private:
  void _nameFunc(Reader *input);
};

#endif // GUILDINVITATIONBYNAMEMESSAGE_H