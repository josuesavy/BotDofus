#ifndef ALLIANCEBULLETINSETERRORMESSAGE_H
#define ALLIANCEBULLETINSETERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/social/SocialNoticeSetErrorMessage.h"

class AllianceBulletinSetErrorMessage : public SocialNoticeSetErrorMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceBulletinSetErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceBulletinSetErrorMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceBulletinSetErrorMessage(FuncTree tree);
  AllianceBulletinSetErrorMessage();
};

#endif // ALLIANCEBULLETINSETERRORMESSAGE_H