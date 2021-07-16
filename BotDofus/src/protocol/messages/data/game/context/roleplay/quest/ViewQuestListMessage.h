#ifndef VIEWQUESTLISTMESSAGE_H
#define VIEWQUESTLISTMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/quest/QuestListMessage.h"

class ViewQuestListMessage : public QuestListMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ViewQuestListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ViewQuestListMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ViewQuestListMessage(FuncTree tree);
  ViewQuestListMessage();
};

#endif // VIEWQUESTLISTMESSAGE_H