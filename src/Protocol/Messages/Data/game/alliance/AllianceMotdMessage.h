#ifndef ALLIANCEMOTDMESSAGE_H
#define ALLIANCEMOTDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/social/SocialNoticeMessage.h"

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