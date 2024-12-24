#ifndef UPDATEGUILDRANKREQUESTMESSAGE_H
#define UPDATEGUILDRANKREQUESTMESSAGE_H

#include "src/protocol/network/types/data/game/rank/RankInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class UpdateGuildRankRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateGuildRankRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateGuildRankRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateGuildRankRequestMessage(FuncTree tree);
  UpdateGuildRankRequestMessage();

  RankInformation rank;

private:
  void _ranktreeFunc(Reader *input);

  FuncTree _ranktree;
};

#endif // UPDATEGUILDRANKREQUESTMESSAGE_H