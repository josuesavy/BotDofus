#ifndef ACTIVITYSUGGESTIONSMESSAGE_H
#define ACTIVITYSUGGESTIONSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ActivitySuggestionsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ActivitySuggestionsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ActivitySuggestionsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ActivitySuggestionsMessage(FuncTree tree);
  ActivitySuggestionsMessage();

  QList<uint> lockedActivitiesIds;
  QList<uint> unlockedActivitiesIds;

private:
  void _lockedActivitiesIdstreeFunc(Reader *input);
  void _lockedActivitiesIdsFunc(Reader *input);
  void _unlockedActivitiesIdstreeFunc(Reader *input);
  void _unlockedActivitiesIdsFunc(Reader *input);

  FuncTree _lockedActivitiesIdstree;
  FuncTree _unlockedActivitiesIdstree;
};

#endif // ACTIVITYSUGGESTIONSMESSAGE_H