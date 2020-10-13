#ifndef GUILDBULLETINMESSAGE_H
#define GUILDBULLETINMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/social/BulletinMessage.h"

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