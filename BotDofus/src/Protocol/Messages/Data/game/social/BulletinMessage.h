#ifndef BULLETINMESSAGE_H
#define BULLETINMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/social/SocialNoticeMessage.h"

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