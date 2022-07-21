#ifndef ALLIANCESUMMARYREQUESTMESSAGE_H
#define ALLIANCESUMMARYREQUESTMESSAGE_H

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

  QString nameFilter;
  QString tagFilter;
  QString playerNameFilter;
  uint sortType;
  bool sortDescending;

private:
  void _nameFilterFunc(Reader *input);
  void _tagFilterFunc(Reader *input);
  void _playerNameFilterFunc(Reader *input);
  void _sortTypeFunc(Reader *input);
  void _sortDescendingFunc(Reader *input);
};

#endif // ALLIANCESUMMARYREQUESTMESSAGE_H