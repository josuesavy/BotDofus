#ifndef UNFOLLOWQUESTOBJECTIVEREQUESTMESSAGE_H
#define UNFOLLOWQUESTOBJECTIVEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class UnfollowQuestObjectiveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UnfollowQuestObjectiveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UnfollowQuestObjectiveRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UnfollowQuestObjectiveRequestMessage(FuncTree tree);
  UnfollowQuestObjectiveRequestMessage();

  uint questId;
  int objectiveId;

private:
  void _questIdFunc(Reader *input);
  void _objectiveIdFunc(Reader *input);
};

#endif // UNFOLLOWQUESTOBJECTIVEREQUESTMESSAGE_H