#ifndef FOLLOWEDQUESTSMESSAGE_H
#define FOLLOWEDQUESTSMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/quest/QuestActiveDetailedInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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