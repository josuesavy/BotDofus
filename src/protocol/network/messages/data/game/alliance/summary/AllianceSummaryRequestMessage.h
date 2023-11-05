#ifndef ALLIANCESUMMARYREQUESTMESSAGE_H
#define ALLIANCESUMMARYREQUESTMESSAGE_H

#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/PaginationRequestAbstractMessage.h"

class AllianceSummaryRequestMessage : public PaginationRequestAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceSummaryRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceSummaryRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceSummaryRequestMessage(FuncTree tree);
  AllianceSummaryRequestMessage();

  int filterType;
  QString textFilter;
  bool hideFullFilter;
  bool followingAllianceCriteria;
  QList<uint> criterionFilter;
  uint sortType;
  bool sortDescending;
  QList<uint> languagesFilter;
  QList<uint> recruitmentTypeFilter;
  uint minPlayerLevelFilter;
  uint maxPlayerLevelFilter;

private:
  void deserializeByteBoxes(Reader *input);
  void _filterTypeFunc(Reader *input);
  void _textFilterFunc(Reader *input);
  void _criterionFiltertreeFunc(Reader *input);
  void _criterionFilterFunc(Reader *input);
  void _sortTypeFunc(Reader *input);
  void _languagesFiltertreeFunc(Reader *input);
  void _languagesFilterFunc(Reader *input);
  void _recruitmentTypeFiltertreeFunc(Reader *input);
  void _recruitmentTypeFilterFunc(Reader *input);
  void _minPlayerLevelFilterFunc(Reader *input);
  void _maxPlayerLevelFilterFunc(Reader *input);

  FuncTree _criterionFiltertree;
  FuncTree _languagesFiltertree;
  FuncTree _recruitmentTypeFiltertree;
};

#endif // ALLIANCESUMMARYREQUESTMESSAGE_H