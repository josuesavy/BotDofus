#ifndef ALLIANCEBULLETINSETREQUESTMESSAGE_H
#define ALLIANCEBULLETINSETREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/social/SocialNoticeSetRequestMessage.h"

class AllianceBulletinSetRequestMessage : public SocialNoticeSetRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceBulletinSetRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceBulletinSetRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceBulletinSetRequestMessage(FuncTree tree);
  AllianceBulletinSetRequestMessage();

  QString content;
  bool notifyMembers;

private:
  void _contentFunc(Reader *input);
  void _notifyMembersFunc(Reader *input);
};

#endif // ALLIANCEBULLETINSETREQUESTMESSAGE_H