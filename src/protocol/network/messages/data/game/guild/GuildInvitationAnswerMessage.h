#ifndef GUILDINVITATIONANSWERMESSAGE_H
#define GUILDINVITATIONANSWERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildInvitationAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInvitationAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInvitationAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInvitationAnswerMessage(FuncTree tree);
  GuildInvitationAnswerMessage();

  bool accept;

private:
  void _acceptFunc(Reader *input);
};

#endif // GUILDINVITATIONANSWERMESSAGE_H