#ifndef ALLIANCESUMMARYMESSAGE_H
#define ALLIANCESUMMARYMESSAGE_H

#include "src/protocol/types/data/game/social/AllianceFactSheetInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/PaginationAnswerAbstractMessage.h"

class AllianceSummaryMessage : public PaginationAnswerAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceSummaryMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceSummaryMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceSummaryMessage(FuncTree tree);
  AllianceSummaryMessage();

  QList<QSharedPointer<AllianceFactSheetInformations>> alliances;

private:
  void _alliancestreeFunc(Reader *input);
  void _alliancesFunc(Reader *input);

  FuncTree _alliancestree;
};

#endif // ALLIANCESUMMARYMESSAGE_H