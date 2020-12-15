#ifndef BULLETINMESSAGE_H
#define BULLETINMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/social/SocialNoticeMessage.h"

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

  uint lastNotifiedTimestamp;

private:
  void _lastNotifiedTimestampFunc(Reader *input);
};

#endif // BULLETINMESSAGE_H