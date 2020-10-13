#ifndef GUILDBULLETINSETREQUESTMESSAGE_H
#define GUILDBULLETINSETREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/social/SocialNoticeSetRequestMessage.h"

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
  bool notifyMembers;

private:
  void _contentFunc(Reader *input);
  void _notifyMembersFunc(Reader *input);
};

#endif // GUILDBULLETINSETREQUESTMESSAGE_H