#ifndef GUILDLISTAPPLICATIONMODIFIEDMESSAGE_H
#define GUILDLISTAPPLICATIONMODIFIEDMESSAGE_H

#include "src/protocol/types/data/game/social/application/SocialApplicationInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildListApplicationModifiedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildListApplicationModifiedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildListApplicationModifiedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildListApplicationModifiedMessage(FuncTree tree);
  GuildListApplicationModifiedMessage();

  SocialApplicationInformation apply;
  uint state;
  double playerId;

private:
  void _applytreeFunc(Reader *input);
  void _stateFunc(Reader *input);
  void _playerIdFunc(Reader *input);

  FuncTree _applytree;
};

#endif // GUILDLISTAPPLICATIONMODIFIEDMESSAGE_H