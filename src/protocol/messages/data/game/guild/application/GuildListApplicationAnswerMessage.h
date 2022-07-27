#ifndef GUILDLISTAPPLICATIONANSWERMESSAGE_H
#define GUILDLISTAPPLICATIONANSWERMESSAGE_H

#include "src/protocol/types/data/game/guild/application/GuildApplicationInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/PaginationAnswerAbstractMessage.h"

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

  QList<QSharedPointer<GuildApplicationInformation>> applies;

private:
  void _appliestreeFunc(Reader *input);
  void _appliesFunc(Reader *input);

  FuncTree _appliestree;
};

#endif // GUILDLISTAPPLICATIONANSWERMESSAGE_H