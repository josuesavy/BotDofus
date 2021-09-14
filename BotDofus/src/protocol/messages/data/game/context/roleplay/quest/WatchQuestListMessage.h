#ifndef WATCHQUESTLISTMESSAGE_H
#define WATCHQUESTLISTMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/quest/QuestListMessage.h"

class WatchQuestListMessage : public QuestListMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_WatchQuestListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_WatchQuestListMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_WatchQuestListMessage(FuncTree tree);
  WatchQuestListMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // WATCHQUESTLISTMESSAGE_H