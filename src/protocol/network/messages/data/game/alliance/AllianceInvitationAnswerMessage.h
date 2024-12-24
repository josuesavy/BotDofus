#ifndef ALLIANCEINVITATIONANSWERMESSAGE_H
#define ALLIANCEINVITATIONANSWERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceInvitationAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceInvitationAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceInvitationAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceInvitationAnswerMessage(FuncTree tree);
  AllianceInvitationAnswerMessage();

  bool accept;

private:
  void _acceptFunc(Reader *input);
};

#endif // ALLIANCEINVITATIONANSWERMESSAGE_H