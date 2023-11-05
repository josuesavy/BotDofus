#ifndef GUILDSUMMARYREQUESTMESSAGE_H
#define GUILDSUMMARYREQUESTMESSAGE_H

#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/PaginationRequestAbstractMessage.h"

class GuildSummaryRequestMessage : public PaginationRequestAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildSummaryRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildSummaryRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildSummaryRequestMessage(FuncTree tree);
  GuildSummaryRequestMessage();

  QString nameFilter;
  bool hideFullFilter;
  QList<uint> criterionFilter;
  QList<uint> languagesFilter;
  QList<uint> recruitmentTypeFilter;
  uint minLevelFilter;
  uint maxLevelFilter;
  uint minPlayerLevelFilter;
  uint maxPlayerLevelFilter;
  uint minSuccessFilter;
  uint maxSuccessFilter;
  uint sortType;
  bool sortDescending;

private:
  void deserializeByteBoxes(Reader *input);
  void _nameFilterFunc(Reader *input);
  void _criterionFiltertreeFunc(Reader *input);
  void _criterionFilterFunc(Reader *input);
  void _languagesFiltertreeFunc(Reader *input);
  void _languagesFilterFunc(Reader *input);
  void _recruitmentTypeFiltertreeFunc(Reader *input);
  void _recruitmentTypeFilterFunc(Reader *input);
  void _minLevelFilterFunc(Reader *input);
  void _maxLevelFilterFunc(Reader *input);
  void _minPlayerLevelFilterFunc(Reader *input);
  void _maxPlayerLevelFilterFunc(Reader *input);
  void _minSuccessFilterFunc(Reader *input);
  void _maxSuccessFilterFunc(Reader *input);
  void _sortTypeFunc(Reader *input);

  FuncTree _criterionFiltertree;
  FuncTree _languagesFiltertree;
  FuncTree _recruitmentTypeFiltertree;
};

#endif // GUILDSUMMARYREQUESTMESSAGE_H