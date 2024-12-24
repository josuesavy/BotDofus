#ifndef FOLLOWEDQUESTSMESSAGE_H
#define FOLLOWEDQUESTSMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/quest/QuestActiveDetailedInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class FollowedQuestsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_FollowedQuestsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_FollowedQuestsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_FollowedQuestsMessage(FuncTree tree);
  FollowedQuestsMessage();

  QList<QSharedPointer<QuestActiveDetailedInformations>> quests;

private:
  void _queststreeFunc(Reader *input);
  void _questsFunc(Reader *input);

  FuncTree _queststree;
};

#endif // FOLLOWEDQUESTSMESSAGE_H