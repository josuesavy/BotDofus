#ifndef ALLIANCEMOTDMESSAGE_H
#define ALLIANCEMOTDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/social/SocialNoticeMessage.h"

class AllianceMotdMessage : public SocialNoticeMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceMotdMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceMotdMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceMotdMessage(FuncTree tree);
  AllianceMotdMessage();
};

#endif // ALLIANCEMOTDMESSAGE_H