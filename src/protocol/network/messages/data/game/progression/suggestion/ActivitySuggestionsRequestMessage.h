#ifndef ACTIVITYSUGGESTIONSREQUESTMESSAGE_H
#define ACTIVITYSUGGESTIONSREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ActivitySuggestionsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ActivitySuggestionsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ActivitySuggestionsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ActivitySuggestionsRequestMessage(FuncTree tree);
  ActivitySuggestionsRequestMessage();

  uint minLevel;
  uint maxLevel;
  uint areaId;
  uint activityCategoryId;
  uint nbCards;

private:
  void _minLevelFunc(Reader *input);
  void _maxLevelFunc(Reader *input);
  void _areaIdFunc(Reader *input);
  void _activityCategoryIdFunc(Reader *input);
  void _nbCardsFunc(Reader *input);
};

#endif // ACTIVITYSUGGESTIONSREQUESTMESSAGE_H