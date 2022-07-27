#ifndef UPDATEALLGUILDRANKREQUESTMESSAGE_H
#define UPDATEALLGUILDRANKREQUESTMESSAGE_H

#include "src/protocol/types/data/game/guild/GuildRankInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class UpdateAllGuildRankRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateAllGuildRankRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateAllGuildRankRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateAllGuildRankRequestMessage(FuncTree tree);
  UpdateAllGuildRankRequestMessage();

  QList<GuildRankInformation> ranks;

private:
  void _rankstreeFunc(Reader *input);
  void _ranksFunc(Reader *input);

  FuncTree _rankstree;
};

#endif // UPDATEALLGUILDRANKREQUESTMESSAGE_H