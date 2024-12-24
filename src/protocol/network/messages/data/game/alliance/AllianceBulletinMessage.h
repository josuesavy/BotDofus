#ifndef ALLIANCEBULLETINMESSAGE_H
#define ALLIANCEBULLETINMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/social/BulletinMessage.h"

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