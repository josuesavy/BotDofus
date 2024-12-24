#ifndef GUILDSUMMARYMESSAGE_H
#define GUILDSUMMARYMESSAGE_H

#include "src/protocol/network/types/data/game/social/GuildFactSheetInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/PaginationAnswerAbstractMessage.h"

class GuildSummaryMessage : public PaginationAnswerAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildSummaryMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildSummaryMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildSummaryMessage(FuncTree tree);
  GuildSummaryMessage();

  QList<QSharedPointer<GuildFactSheetInformations>> guilds;

private:
  void _guildstreeFunc(Reader *input);
  void _guildsFunc(Reader *input);

  FuncTree _guildstree;
};

#endif // GUILDSUMMARYMESSAGE_H