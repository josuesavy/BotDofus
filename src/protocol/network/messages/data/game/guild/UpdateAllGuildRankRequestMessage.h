#ifndef UPDATEALLGUILDRANKREQUESTMESSAGE_H
#define UPDATEALLGUILDRANKREQUESTMESSAGE_H

#include "src/protocol/network/types/data/game/rank/RankInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  QList<RankInformation> ranks;

private:
  void _rankstreeFunc(Reader *input);
  void _ranksFunc(Reader *input);

  FuncTree _rankstree;
};

#endif // UPDATEALLGUILDRANKREQUESTMESSAGE_H