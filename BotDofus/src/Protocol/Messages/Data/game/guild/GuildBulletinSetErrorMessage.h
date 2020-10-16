#ifndef GUILDBULLETINSETERRORMESSAGE_H
#define GUILDBULLETINSETERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/social/SocialNoticeSetErrorMessage.h"

class GuildBulletinSetErrorMessage : public SocialNoticeSetErrorMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildBulletinSetErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildBulletinSetErrorMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildBulletinSetErrorMessage(FuncTree tree);
  GuildBulletinSetErrorMessage();
};

#endif // GUILDBULLETINSETERRORMESSAGE_H