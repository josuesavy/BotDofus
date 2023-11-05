#ifndef GUILDBULLETINSETREQUESTMESSAGE_H
#define GUILDBULLETINSETREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/social/SocialNoticeSetRequestMessage.h"

class GuildBulletinSetRequestMessage : public SocialNoticeSetRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildBulletinSetRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildBulletinSetRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildBulletinSetRequestMessage(FuncTree tree);
  GuildBulletinSetRequestMessage();

  QString content;

private:
  void _contentFunc(Reader *input);
};

#endif // GUILDBULLETINSETREQUESTMESSAGE_H