#ifndef GUILDAPPLICATIONANSWERMESSAGE_H
#define GUILDAPPLICATIONANSWERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildApplicationAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildApplicationAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildApplicationAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildApplicationAnswerMessage(FuncTree tree);
  GuildApplicationAnswerMessage();

  bool accepted;
  uint playerId;

private:
  void _acceptedFunc(Reader *input);
  void _playerIdFunc(Reader *input);
};

#endif // GUILDAPPLICATIONANSWERMESSAGE_H