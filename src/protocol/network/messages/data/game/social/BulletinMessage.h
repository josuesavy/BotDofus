#ifndef BULLETINMESSAGE_H
#define BULLETINMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/social/SocialNoticeMessage.h"

class BulletinMessage : public SocialNoticeMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BulletinMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BulletinMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BulletinMessage(FuncTree tree);
  BulletinMessage();
};

#endif // BULLETINMESSAGE_H