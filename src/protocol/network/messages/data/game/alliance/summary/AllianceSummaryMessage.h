#ifndef ALLIANCESUMMARYMESSAGE_H
#define ALLIANCESUMMARYMESSAGE_H

#include "src/protocol/network/types/data/game/social/AllianceFactSheetInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/PaginationAnswerAbstractMessage.h"

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

  QList<QSharedPointer<AllianceFactSheetInformation>> alliances;

private:
  void _alliancestreeFunc(Reader *input);
  void _alliancesFunc(Reader *input);

  FuncTree _alliancestree;
};

#endif // ALLIANCESUMMARYMESSAGE_H