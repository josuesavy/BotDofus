#ifndef ALLIANCEBULLETINMESSAGE_H
#define ALLIANCEBULLETINMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/social/BulletinMessage.h"

class AllianceBulletinMessage : public BulletinMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceBulletinMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceBulletinMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceBulletinMessage(FuncTree tree);
  AllianceBulletinMessage();
};

#endif // ALLIANCEBULLETINMESSAGE_H