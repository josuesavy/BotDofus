#ifndef GUILDBULLETINMESSAGE_H
#define GUILDBULLETINMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/social/BulletinMessage.h"

class GuildBulletinMessage : public BulletinMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildBulletinMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildBulletinMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildBulletinMessage(FuncTree tree);
  GuildBulletinMessage();
};

#endif // GUILDBULLETINMESSAGE_H