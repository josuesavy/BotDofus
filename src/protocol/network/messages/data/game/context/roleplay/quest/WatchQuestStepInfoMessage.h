#ifndef WATCHQUESTSTEPINFOMESSAGE_H
#define WATCHQUESTSTEPINFOMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/quest/QuestStepInfoMessage.h"

class WatchQuestStepInfoMessage : public QuestStepInfoMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_WatchQuestStepInfoMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_WatchQuestStepInfoMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_WatchQuestStepInfoMessage(FuncTree tree);
  WatchQuestStepInfoMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // WATCHQUESTSTEPINFOMESSAGE_H