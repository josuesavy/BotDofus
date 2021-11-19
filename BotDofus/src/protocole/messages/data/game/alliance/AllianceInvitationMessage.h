#ifndef ALLIANCEINVITATIONMESSAGE_H
#define ALLIANCEINVITATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceInvitationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceInvitationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceInvitationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceInvitationMessage(FuncTree tree);
  AllianceInvitationMessage();

  double targetId;

private:
  void _targetIdFunc(Reader *input);
};

#endif // ALLIANCEINVITATIONMESSAGE_H