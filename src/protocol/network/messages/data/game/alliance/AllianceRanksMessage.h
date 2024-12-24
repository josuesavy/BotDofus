#ifndef ALLIANCERANKSMESSAGE_H
#define ALLIANCERANKSMESSAGE_H

#include "src/protocol/network/types/data/game/rank/RankInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceRanksMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceRanksMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceRanksMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceRanksMessage(FuncTree tree);
  AllianceRanksMessage();

  QList<RankInformation> ranks;

private:
  void _rankstreeFunc(Reader *input);
  void _ranksFunc(Reader *input);

  FuncTree _rankstree;
};

#endif // ALLIANCERANKSMESSAGE_H