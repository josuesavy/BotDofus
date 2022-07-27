#ifndef GUILDSUMMARYMESSAGE_H
#define GUILDSUMMARYMESSAGE_H

#include "src/protocol/types/data/game/social/GuildFactSheetInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/PaginationAnswerAbstractMessage.h"

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