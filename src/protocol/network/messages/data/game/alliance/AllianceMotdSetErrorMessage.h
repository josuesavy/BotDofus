#ifndef ALLIANCEMOTDSETERRORMESSAGE_H
#define ALLIANCEMOTDSETERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/social/SocialNoticeSetErrorMessage.h"

class AllianceMotdSetErrorMessage : public SocialNoticeSetErrorMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceMotdSetErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceMotdSetErrorMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceMotdSetErrorMessage(FuncTree tree);
  AllianceMotdSetErrorMessage();
};

#endif // ALLIANCEMOTDSETERRORMESSAGE_H