#ifndef GUILDLISTAPPLICATIONANSWERMESSAGE_H
#define GUILDLISTAPPLICATIONANSWERMESSAGE_H

#include "src/protocol/network/types/data/game/social/application/SocialApplicationInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/PaginationAnswerAbstractMessage.h"

class GuildListApplicationAnswerMessage : public PaginationAnswerAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildListApplicationAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildListApplicationAnswerMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildListApplicationAnswerMessage(FuncTree tree);
  GuildListApplicationAnswerMessage();

  QList<QSharedPointer<SocialApplicationInformation>> applies;

private:
  void _appliestreeFunc(Reader *input);
  void _appliesFunc(Reader *input);

  FuncTree _appliestree;
};

#endif // GUILDLISTAPPLICATIONANSWERMESSAGE_H