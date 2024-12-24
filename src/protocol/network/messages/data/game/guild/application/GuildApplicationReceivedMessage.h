#ifndef GUILDAPPLICATIONRECEIVEDMESSAGE_H
#define GUILDAPPLICATIONRECEIVEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildApplicationReceivedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildApplicationReceivedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildApplicationReceivedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildApplicationReceivedMessage(FuncTree tree);
  GuildApplicationReceivedMessage();

  QString playerName;
  double playerId;

private:
  void _playerNameFunc(Reader *input);
  void _playerIdFunc(Reader *input);
};

#endif // GUILDAPPLICATIONRECEIVEDMESSAGE_H