#ifndef FOLLOWQUESTOBJECTIVEREQUESTMESSAGE_H
#define FOLLOWQUESTOBJECTIVEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class FollowQuestObjectiveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FollowQuestObjectiveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FollowQuestObjectiveRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FollowQuestObjectiveRequestMessage(FuncTree tree);
  FollowQuestObjectiveRequestMessage();

  uint questId;
  int objectiveId;

private:
  void _questIdFunc(Reader *input);
  void _objectiveIdFunc(Reader *input);
};

#endif // FOLLOWQUESTOBJECTIVEREQUESTMESSAGE_H