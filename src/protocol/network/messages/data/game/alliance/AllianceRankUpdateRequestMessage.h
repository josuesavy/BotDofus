#ifndef ALLIANCERANKUPDATEREQUESTMESSAGE_H
#define ALLIANCERANKUPDATEREQUESTMESSAGE_H

#include "src/protocol/network/types/data/game/rank/RankInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceRankUpdateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceRankUpdateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceRankUpdateRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceRankUpdateRequestMessage(FuncTree tree);
  AllianceRankUpdateRequestMessage();

  RankInformation rank;

private:
  void _ranktreeFunc(Reader *input);

  FuncTree _ranktree;
};

#endif // ALLIANCERANKUPDATEREQUESTMESSAGE_H