#ifndef ALLIANCEALLRANKSUPDATEREQUESTMESSAGE_H
#define ALLIANCEALLRANKSUPDATEREQUESTMESSAGE_H

#include "src/protocol/types/data/game/rank/RankInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceAllRanksUpdateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceAllRanksUpdateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceAllRanksUpdateRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceAllRanksUpdateRequestMessage(FuncTree tree);
  AllianceAllRanksUpdateRequestMessage();

  QList<RankInformation> ranks;

private:
  void _rankstreeFunc(Reader *input);
  void _ranksFunc(Reader *input);

  FuncTree _rankstree;
};

#endif // ALLIANCEALLRANKSUPDATEREQUESTMESSAGE_H