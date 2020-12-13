#ifndef ALLIANCEMOTDSETREQUESTMESSAGE_H
#define ALLIANCEMOTDSETREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/social/SocialNoticeSetRequestMessage.h"

class AllianceMotdSetRequestMessage : public SocialNoticeSetRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceMotdSetRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceMotdSetRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceMotdSetRequestMessage(FuncTree tree);
  AllianceMotdSetRequestMessage();

  QString content;

private:
  void _contentFunc(Reader *input);
};

#endif // ALLIANCEMOTDSETREQUESTMESSAGE_H