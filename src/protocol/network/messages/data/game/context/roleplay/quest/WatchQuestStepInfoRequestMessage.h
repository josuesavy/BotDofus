#ifndef WATCHQUESTSTEPINFOREQUESTMESSAGE_H
#define WATCHQUESTSTEPINFOREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/quest/QuestStepInfoRequestMessage.h"

class WatchQuestStepInfoRequestMessage : public QuestStepInfoRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_WatchQuestStepInfoRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_WatchQuestStepInfoRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_WatchQuestStepInfoRequestMessage(FuncTree tree);
  WatchQuestStepInfoRequestMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // WATCHQUESTSTEPINFOREQUESTMESSAGE_H